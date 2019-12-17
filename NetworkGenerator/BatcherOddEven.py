import math
import sys
import SortingNetwork as SortNet


class BatcherOddEven(SortNet.SortingNetwork):
    def generate_serial_network(self):
        t = math.ceil(math.log2(self.num_input))
        p = int(2**(t-1))

        for p in [int(2**(t-i-1)) for i in range(t)]:
            q = int(2**(t-1))
            r = 0
            d = p

            while True:
                for i in range(self.num_input-d):
                    if i & p == r:
                        self.serialNet.append([i, i+d])
                if q != p:
                    d = q-p
                    q = int(q/2)
                    r = p
                else:
                    break

if __name__ == "__main__":

    n = 9

    if len(sys.argv) < 3:
        print("Usage:")
        print("python BatcherOddEven.py N out.json")
    else:
        n=int(sys.argv[1])

    sorter = BatcherOddEven(num_input=n)
    sorter.generate()
    sorter.export(sys.argv[2])
