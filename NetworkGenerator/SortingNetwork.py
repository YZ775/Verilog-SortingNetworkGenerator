import copy
import json
import math


class SortingNetwork(object):

    serialNet = None  # 直列なネットワーク(暫定的)
    network = None  # 並列化されたネットワーク
    num_input = 0  # ネットワークの入力の数

    def __init__(self, num_input=None):
        if num_input is None:
            self.num_input=2
        self.num_input = num_input
        self.network = []
        self.serialNet = []

    def export(self, filename):
        """
        生成されたソーティングネットワークをjsonファイルに出力する。

        jsonファイルは"size"と"network"のふたつにキーをもち、
        sizeはネットワークの入力のサイズ、"network"はネットワークである。
        """

        dst = json.dumps({"size": self.num_input, "network": self.network})

        # 人間が読みやすいように整形する
        dst = dst.replace('"size"', '\n"size"')
        dst = dst.replace(']], ', ']],\n\t\t')

        with open(filename, 'w') as f:
            f.write(dst)

    def cutoff(self):
        '''
        生成された直列なネットワークに対して中央値の出力に用いられないコンパレータを削除する
        '''
        used = [False]*self.num_input
        mid = int(math.floor(self.num_input/2))
        used[mid] = True

        for i in range(len(self.serialNet))[::-1]:
            if used[self.serialNet[i][0]] or used[self.serialNet[i][1]]:
                used[self.serialNet[i][0]] = True
                used[self.serialNet[i][1]] = True
            else:
                del(self.serialNet[i])

    def parallelize(self):
        '''
        生成された直列なネットワークを並列実行できる形式に変更する
        '''
        layer = []
        layer_pins = set()

        for comp in self.serialNet:
            if (comp[0] in layer_pins) or (comp[1] in layer_pins):
                self.network.append(copy.deepcopy(layer))
                layer.clear()
                layer_pins.clear()

            layer.append(comp)
            layer_pins.add(comp[0])
            layer_pins.add(comp[1])
        else:
            self.network.append(copy.deepcopy(layer))

    def generate_serial_network(self):
        '''
        直列化したネットワークを生成する
        いろいろな方法があるので各自実装する
        '''
        raise NotImplementedError

    def generate(self):
        '''
        ソーティングネットワークの生成
        '''
        self.generate_serial_network()
        self.cutoff()
        self.parallelize()

    def exec(self,data):
        '''
        ソーティングネットワークを実行する

        data: iterableな数値の入ったもの
        '''
        for layer in self.network:
            for comp in layer:
                i = comp[0]
                j = comp[1]
                if data[i] > data[j]:
                    data[i], data[j] = data[j], data[i]
        