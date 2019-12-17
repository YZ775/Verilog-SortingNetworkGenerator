#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <omp.h>
#include <random>

#include <chrono>

using namespace std;

const int num_elem = 1e6;
const int size_elem = 9 * 9;

inline void comp(int8_t *v, int a, int b)
{
    int8_t va = v[a];
    int8_t vb = v[b];
    v[a] = va < vb ? va : vb;
    v[b] = va < vb ? vb : va;
}

inline void sorter(int8_t *vec)
{
    comp(vec, 0, 64);
    comp(vec, 1, 65);
    comp(vec, 2, 66);
    comp(vec, 3, 67);
    comp(vec, 4, 68);
    comp(vec, 5, 69);
    comp(vec, 6, 70);
    comp(vec, 7, 71);
    comp(vec, 8, 72);
    comp(vec, 9, 73);
    comp(vec, 10, 74);
    comp(vec, 11, 75);
    comp(vec, 12, 76);
    comp(vec, 13, 77);
    comp(vec, 14, 78);
    comp(vec, 15, 79);
    comp(vec, 16, 80);
    comp(vec, 0, 32);
    comp(vec, 1, 33);
    comp(vec, 2, 34);
    comp(vec, 3, 35);
    comp(vec, 4, 36);
    comp(vec, 5, 37);
    comp(vec, 6, 38);
    comp(vec, 7, 39);
    comp(vec, 8, 40);
    comp(vec, 9, 41);
    comp(vec, 10, 42);
    comp(vec, 11, 43);
    comp(vec, 12, 44);
    comp(vec, 13, 45);
    comp(vec, 14, 46);
    comp(vec, 15, 47);
    comp(vec, 16, 48);
    comp(vec, 17, 49);
    comp(vec, 18, 50);
    comp(vec, 19, 51);
    comp(vec, 20, 52);
    comp(vec, 21, 53);
    comp(vec, 22, 54);
    comp(vec, 23, 55);
    comp(vec, 24, 56);
    comp(vec, 25, 57);
    comp(vec, 26, 58);
    comp(vec, 27, 59);
    comp(vec, 28, 60);
    comp(vec, 29, 61);
    comp(vec, 30, 62);
    comp(vec, 31, 63);
    comp(vec, 32, 64);
    comp(vec, 33, 65);
    comp(vec, 34, 66);
    comp(vec, 35, 67);
    comp(vec, 36, 68);
    comp(vec, 37, 69);
    comp(vec, 38, 70);
    comp(vec, 39, 71);
    comp(vec, 40, 72);
    comp(vec, 41, 73);
    comp(vec, 42, 74);
    comp(vec, 43, 75);
    comp(vec, 44, 76);
    comp(vec, 45, 77);
    comp(vec, 46, 78);
    comp(vec, 47, 79);
    comp(vec, 48, 80);
    comp(vec, 0, 16);
    comp(vec, 1, 17);
    comp(vec, 2, 18);
    comp(vec, 3, 19);
    comp(vec, 4, 20);
    comp(vec, 5, 21);
    comp(vec, 6, 22);
    comp(vec, 7, 23);
    comp(vec, 8, 24);
    comp(vec, 9, 25);
    comp(vec, 10, 26);
    comp(vec, 11, 27);
    comp(vec, 12, 28);
    comp(vec, 13, 29);
    comp(vec, 14, 30);
    comp(vec, 15, 31);
    comp(vec, 32, 48);
    comp(vec, 33, 49);
    comp(vec, 34, 50);
    comp(vec, 35, 51);
    comp(vec, 36, 52);
    comp(vec, 37, 53);
    comp(vec, 38, 54);
    comp(vec, 39, 55);
    comp(vec, 40, 56);
    comp(vec, 41, 57);
    comp(vec, 42, 58);
    comp(vec, 43, 59);
    comp(vec, 44, 60);
    comp(vec, 45, 61);
    comp(vec, 46, 62);
    comp(vec, 47, 63);
    comp(vec, 64, 80);
    comp(vec, 16, 64);
    comp(vec, 17, 65);
    comp(vec, 18, 66);
    comp(vec, 19, 67);
    comp(vec, 20, 68);
    comp(vec, 21, 69);
    comp(vec, 22, 70);
    comp(vec, 23, 71);
    comp(vec, 24, 72);
    comp(vec, 25, 73);
    comp(vec, 26, 74);
    comp(vec, 27, 75);
    comp(vec, 28, 76);
    comp(vec, 29, 77);
    comp(vec, 30, 78);
    comp(vec, 31, 79);
    comp(vec, 16, 32);
    comp(vec, 17, 33);
    comp(vec, 18, 34);
    comp(vec, 19, 35);
    comp(vec, 20, 36);
    comp(vec, 21, 37);
    comp(vec, 22, 38);
    comp(vec, 23, 39);
    comp(vec, 24, 40);
    comp(vec, 25, 41);
    comp(vec, 26, 42);
    comp(vec, 27, 43);
    comp(vec, 28, 44);
    comp(vec, 29, 45);
    comp(vec, 30, 46);
    comp(vec, 31, 47);
    comp(vec, 48, 64);
    comp(vec, 49, 65);
    comp(vec, 50, 66);
    comp(vec, 51, 67);
    comp(vec, 52, 68);
    comp(vec, 53, 69);
    comp(vec, 54, 70);
    comp(vec, 55, 71);
    comp(vec, 56, 72);
    comp(vec, 57, 73);
    comp(vec, 58, 74);
    comp(vec, 59, 75);
    comp(vec, 60, 76);
    comp(vec, 61, 77);
    comp(vec, 62, 78);
    comp(vec, 63, 79);
    comp(vec, 0, 8);
    comp(vec, 1, 9);
    comp(vec, 2, 10);
    comp(vec, 3, 11);
    comp(vec, 4, 12);
    comp(vec, 5, 13);
    comp(vec, 6, 14);
    comp(vec, 7, 15);
    comp(vec, 16, 24);
    comp(vec, 17, 25);
    comp(vec, 18, 26);
    comp(vec, 19, 27);
    comp(vec, 20, 28);
    comp(vec, 21, 29);
    comp(vec, 22, 30);
    comp(vec, 23, 31);
    comp(vec, 32, 40);
    comp(vec, 33, 41);
    comp(vec, 34, 42);
    comp(vec, 35, 43);
    comp(vec, 36, 44);
    comp(vec, 37, 45);
    comp(vec, 38, 46);
    comp(vec, 39, 47);
    comp(vec, 48, 56);
    comp(vec, 49, 57);
    comp(vec, 50, 58);
    comp(vec, 51, 59);
    comp(vec, 52, 60);
    comp(vec, 53, 61);
    comp(vec, 54, 62);
    comp(vec, 55, 63);
    comp(vec, 64, 72);
    comp(vec, 65, 73);
    comp(vec, 66, 74);
    comp(vec, 67, 75);
    comp(vec, 68, 76);
    comp(vec, 69, 77);
    comp(vec, 70, 78);
    comp(vec, 71, 79);
    comp(vec, 8, 64);
    comp(vec, 9, 65);
    comp(vec, 10, 66);
    comp(vec, 11, 67);
    comp(vec, 12, 68);
    comp(vec, 13, 69);
    comp(vec, 14, 70);
    comp(vec, 15, 71);
    comp(vec, 24, 80);
    comp(vec, 8, 32);
    comp(vec, 9, 33);
    comp(vec, 10, 34);
    comp(vec, 11, 35);
    comp(vec, 12, 36);
    comp(vec, 13, 37);
    comp(vec, 14, 38);
    comp(vec, 15, 39);
    comp(vec, 24, 48);
    comp(vec, 25, 49);
    comp(vec, 26, 50);
    comp(vec, 27, 51);
    comp(vec, 28, 52);
    comp(vec, 29, 53);
    comp(vec, 30, 54);
    comp(vec, 31, 55);
    comp(vec, 40, 64);
    comp(vec, 41, 65);
    comp(vec, 42, 66);
    comp(vec, 43, 67);
    comp(vec, 44, 68);
    comp(vec, 45, 69);
    comp(vec, 46, 70);
    comp(vec, 47, 71);
    comp(vec, 56, 80);
    comp(vec, 8, 16);
    comp(vec, 9, 17);
    comp(vec, 10, 18);
    comp(vec, 11, 19);
    comp(vec, 12, 20);
    comp(vec, 13, 21);
    comp(vec, 14, 22);
    comp(vec, 15, 23);
    comp(vec, 24, 32);
    comp(vec, 25, 33);
    comp(vec, 26, 34);
    comp(vec, 27, 35);
    comp(vec, 28, 36);
    comp(vec, 29, 37);
    comp(vec, 30, 38);
    comp(vec, 31, 39);
    comp(vec, 40, 48);
    comp(vec, 41, 49);
    comp(vec, 42, 50);
    comp(vec, 43, 51);
    comp(vec, 44, 52);
    comp(vec, 45, 53);
    comp(vec, 46, 54);
    comp(vec, 47, 55);
    comp(vec, 56, 64);
    comp(vec, 57, 65);
    comp(vec, 58, 66);
    comp(vec, 59, 67);
    comp(vec, 60, 68);
    comp(vec, 61, 69);
    comp(vec, 62, 70);
    comp(vec, 63, 71);
    comp(vec, 72, 80);
    comp(vec, 0, 4);
    comp(vec, 1, 5);
    comp(vec, 2, 6);
    comp(vec, 3, 7);
    comp(vec, 8, 12);
    comp(vec, 9, 13);
    comp(vec, 10, 14);
    comp(vec, 11, 15);
    comp(vec, 16, 20);
    comp(vec, 17, 21);
    comp(vec, 18, 22);
    comp(vec, 19, 23);
    comp(vec, 24, 28);
    comp(vec, 25, 29);
    comp(vec, 26, 30);
    comp(vec, 27, 31);
    comp(vec, 32, 36);
    comp(vec, 33, 37);
    comp(vec, 34, 38);
    comp(vec, 35, 39);
    comp(vec, 40, 44);
    comp(vec, 41, 45);
    comp(vec, 42, 46);
    comp(vec, 43, 47);
    comp(vec, 48, 52);
    comp(vec, 49, 53);
    comp(vec, 50, 54);
    comp(vec, 51, 55);
    comp(vec, 56, 60);
    comp(vec, 57, 61);
    comp(vec, 58, 62);
    comp(vec, 59, 63);
    comp(vec, 64, 68);
    comp(vec, 65, 69);
    comp(vec, 66, 70);
    comp(vec, 67, 71);
    comp(vec, 72, 76);
    comp(vec, 73, 77);
    comp(vec, 74, 78);
    comp(vec, 75, 79);
    comp(vec, 4, 64);
    comp(vec, 5, 65);
    comp(vec, 6, 66);
    comp(vec, 7, 67);
    comp(vec, 12, 72);
    comp(vec, 13, 73);
    comp(vec, 14, 74);
    comp(vec, 15, 75);
    comp(vec, 20, 80);
    comp(vec, 4, 32);
    comp(vec, 5, 33);
    comp(vec, 6, 34);
    comp(vec, 7, 35);
    comp(vec, 12, 40);
    comp(vec, 13, 41);
    comp(vec, 14, 42);
    comp(vec, 15, 43);
    comp(vec, 20, 48);
    comp(vec, 21, 49);
    comp(vec, 22, 50);
    comp(vec, 23, 51);
    comp(vec, 28, 56);
    comp(vec, 29, 57);
    comp(vec, 30, 58);
    comp(vec, 31, 59);
    comp(vec, 36, 64);
    comp(vec, 37, 65);
    comp(vec, 38, 66);
    comp(vec, 39, 67);
    comp(vec, 44, 72);
    comp(vec, 45, 73);
    comp(vec, 46, 74);
    comp(vec, 47, 75);
    comp(vec, 52, 80);
    comp(vec, 4, 16);
    comp(vec, 5, 17);
    comp(vec, 6, 18);
    comp(vec, 7, 19);
    comp(vec, 12, 24);
    comp(vec, 13, 25);
    comp(vec, 14, 26);
    comp(vec, 15, 27);
    comp(vec, 20, 32);
    comp(vec, 21, 33);
    comp(vec, 22, 34);
    comp(vec, 23, 35);
    comp(vec, 28, 40);
    comp(vec, 29, 41);
    comp(vec, 30, 42);
    comp(vec, 31, 43);
    comp(vec, 36, 48);
    comp(vec, 37, 49);
    comp(vec, 38, 50);
    comp(vec, 39, 51);
    comp(vec, 44, 56);
    comp(vec, 45, 57);
    comp(vec, 46, 58);
    comp(vec, 47, 59);
    comp(vec, 52, 64);
    comp(vec, 53, 65);
    comp(vec, 54, 66);
    comp(vec, 55, 67);
    comp(vec, 60, 72);
    comp(vec, 61, 73);
    comp(vec, 62, 74);
    comp(vec, 63, 75);
    comp(vec, 68, 80);
    comp(vec, 4, 8);
    comp(vec, 5, 9);
    comp(vec, 6, 10);
    comp(vec, 7, 11);
    comp(vec, 12, 16);
    comp(vec, 13, 17);
    comp(vec, 14, 18);
    comp(vec, 15, 19);
    comp(vec, 20, 24);
    comp(vec, 21, 25);
    comp(vec, 22, 26);
    comp(vec, 23, 27);
    comp(vec, 28, 32);
    comp(vec, 29, 33);
    comp(vec, 30, 34);
    comp(vec, 31, 35);
    comp(vec, 36, 40);
    comp(vec, 37, 41);
    comp(vec, 38, 42);
    comp(vec, 39, 43);
    comp(vec, 44, 48);
    comp(vec, 45, 49);
    comp(vec, 46, 50);
    comp(vec, 47, 51);
    comp(vec, 52, 56);
    comp(vec, 53, 57);
    comp(vec, 54, 58);
    comp(vec, 55, 59);
    comp(vec, 60, 64);
    comp(vec, 61, 65);
    comp(vec, 62, 66);
    comp(vec, 63, 67);
    comp(vec, 68, 72);
    comp(vec, 69, 73);
    comp(vec, 70, 74);
    comp(vec, 71, 75);
    comp(vec, 76, 80);
    comp(vec, 0, 2);
    comp(vec, 1, 3);
    comp(vec, 4, 6);
    comp(vec, 5, 7);
    comp(vec, 8, 10);
    comp(vec, 9, 11);
    comp(vec, 12, 14);
    comp(vec, 13, 15);
    comp(vec, 16, 18);
    comp(vec, 17, 19);
    comp(vec, 20, 22);
    comp(vec, 21, 23);
    comp(vec, 24, 26);
    comp(vec, 25, 27);
    comp(vec, 28, 30);
    comp(vec, 29, 31);
    comp(vec, 32, 34);
    comp(vec, 33, 35);
    comp(vec, 36, 38);
    comp(vec, 37, 39);
    comp(vec, 40, 42);
    comp(vec, 41, 43);
    comp(vec, 44, 46);
    comp(vec, 45, 47);
    comp(vec, 48, 50);
    comp(vec, 49, 51);
    comp(vec, 52, 54);
    comp(vec, 53, 55);
    comp(vec, 56, 58);
    comp(vec, 57, 59);
    comp(vec, 60, 62);
    comp(vec, 61, 63);
    comp(vec, 64, 66);
    comp(vec, 65, 67);
    comp(vec, 68, 70);
    comp(vec, 69, 71);
    comp(vec, 72, 74);
    comp(vec, 73, 75);
    comp(vec, 76, 78);
    comp(vec, 77, 79);
    comp(vec, 2, 64);
    comp(vec, 3, 65);
    comp(vec, 6, 68);
    comp(vec, 7, 69);
    comp(vec, 10, 72);
    comp(vec, 11, 73);
    comp(vec, 14, 76);
    comp(vec, 15, 77);
    comp(vec, 18, 80);
    comp(vec, 2, 32);
    comp(vec, 3, 33);
    comp(vec, 6, 36);
    comp(vec, 7, 37);
    comp(vec, 10, 40);
    comp(vec, 11, 41);
    comp(vec, 14, 44);
    comp(vec, 15, 45);
    comp(vec, 18, 48);
    comp(vec, 19, 49);
    comp(vec, 22, 52);
    comp(vec, 23, 53);
    comp(vec, 26, 56);
    comp(vec, 27, 57);
    comp(vec, 30, 60);
    comp(vec, 31, 61);
    comp(vec, 34, 64);
    comp(vec, 35, 65);
    comp(vec, 38, 68);
    comp(vec, 39, 69);
    comp(vec, 42, 72);
    comp(vec, 43, 73);
    comp(vec, 46, 76);
    comp(vec, 47, 77);
    comp(vec, 50, 80);
    comp(vec, 2, 16);
    comp(vec, 3, 17);
    comp(vec, 6, 20);
    comp(vec, 7, 21);
    comp(vec, 10, 24);
    comp(vec, 11, 25);
    comp(vec, 14, 28);
    comp(vec, 15, 29);
    comp(vec, 18, 32);
    comp(vec, 19, 33);
    comp(vec, 22, 36);
    comp(vec, 23, 37);
    comp(vec, 26, 40);
    comp(vec, 27, 41);
    comp(vec, 30, 44);
    comp(vec, 31, 45);
    comp(vec, 34, 48);
    comp(vec, 35, 49);
    comp(vec, 38, 52);
    comp(vec, 39, 53);
    comp(vec, 42, 56);
    comp(vec, 43, 57);
    comp(vec, 46, 60);
    comp(vec, 47, 61);
    comp(vec, 50, 64);
    comp(vec, 51, 65);
    comp(vec, 54, 68);
    comp(vec, 55, 69);
    comp(vec, 58, 72);
    comp(vec, 59, 73);
    comp(vec, 62, 76);
    comp(vec, 63, 77);
    comp(vec, 66, 80);
    comp(vec, 2, 8);
    comp(vec, 3, 9);
    comp(vec, 6, 12);
    comp(vec, 7, 13);
    comp(vec, 10, 16);
    comp(vec, 11, 17);
    comp(vec, 14, 20);
    comp(vec, 15, 21);
    comp(vec, 18, 24);
    comp(vec, 19, 25);
    comp(vec, 22, 28);
    comp(vec, 23, 29);
    comp(vec, 26, 32);
    comp(vec, 27, 33);
    comp(vec, 30, 36);
    comp(vec, 31, 37);
    comp(vec, 34, 40);
    comp(vec, 35, 41);
    comp(vec, 38, 44);
    comp(vec, 39, 45);
    comp(vec, 42, 48);
    comp(vec, 43, 49);
    comp(vec, 46, 52);
    comp(vec, 47, 53);
    comp(vec, 50, 56);
    comp(vec, 51, 57);
    comp(vec, 54, 60);
    comp(vec, 55, 61);
    comp(vec, 58, 64);
    comp(vec, 59, 65);
    comp(vec, 62, 68);
    comp(vec, 63, 69);
    comp(vec, 66, 72);
    comp(vec, 67, 73);
    comp(vec, 70, 76);
    comp(vec, 71, 77);
    comp(vec, 74, 80);
    comp(vec, 2, 4);
    comp(vec, 3, 5);
    comp(vec, 6, 8);
    comp(vec, 7, 9);
    comp(vec, 10, 12);
    comp(vec, 11, 13);
    comp(vec, 14, 16);
    comp(vec, 15, 17);
    comp(vec, 18, 20);
    comp(vec, 19, 21);
    comp(vec, 22, 24);
    comp(vec, 23, 25);
    comp(vec, 26, 28);
    comp(vec, 27, 29);
    comp(vec, 30, 32);
    comp(vec, 31, 33);
    comp(vec, 34, 36);
    comp(vec, 35, 37);
    comp(vec, 38, 40);
    comp(vec, 39, 41);
    comp(vec, 42, 44);
    comp(vec, 43, 45);
    comp(vec, 46, 48);
    comp(vec, 47, 49);
    comp(vec, 50, 52);
    comp(vec, 51, 53);
    comp(vec, 54, 56);
    comp(vec, 55, 57);
    comp(vec, 58, 60);
    comp(vec, 59, 61);
    comp(vec, 62, 64);
    comp(vec, 63, 65);
    comp(vec, 66, 68);
    comp(vec, 67, 69);
    comp(vec, 70, 72);
    comp(vec, 71, 73);
    comp(vec, 74, 76);
    comp(vec, 75, 77);
    comp(vec, 78, 80);
    comp(vec, 0, 1);
    comp(vec, 2, 3);
    comp(vec, 4, 5);
    comp(vec, 6, 7);
    comp(vec, 8, 9);
    comp(vec, 10, 11);
    comp(vec, 12, 13);
    comp(vec, 14, 15);
    comp(vec, 16, 17);
    comp(vec, 18, 19);
    comp(vec, 20, 21);
    comp(vec, 22, 23);
    comp(vec, 24, 25);
    comp(vec, 26, 27);
    comp(vec, 28, 29);
    comp(vec, 30, 31);
    comp(vec, 32, 33);
    comp(vec, 34, 35);
    comp(vec, 36, 37);
    comp(vec, 38, 39);
    comp(vec, 40, 41);
    comp(vec, 42, 43);
    comp(vec, 44, 45);
    comp(vec, 46, 47);
    comp(vec, 48, 49);
    comp(vec, 50, 51);
    comp(vec, 52, 53);
    comp(vec, 54, 55);
    comp(vec, 56, 57);
    comp(vec, 58, 59);
    comp(vec, 60, 61);
    comp(vec, 62, 63);
    comp(vec, 64, 65);
    comp(vec, 66, 67);
    comp(vec, 68, 69);
    comp(vec, 70, 71);
    comp(vec, 72, 73);
    comp(vec, 74, 75);
    comp(vec, 76, 77);
    comp(vec, 78, 79);
    comp(vec, 1, 64);
    comp(vec, 3, 66);
    comp(vec, 5, 68);
    comp(vec, 7, 70);
    comp(vec, 9, 72);
    comp(vec, 11, 74);
    comp(vec, 13, 76);
    comp(vec, 15, 78);
    comp(vec, 17, 80);
    comp(vec, 9, 40);
    comp(vec, 11, 42);
    comp(vec, 13, 44);
    comp(vec, 15, 46);
    comp(vec, 17, 48);
    comp(vec, 19, 50);
    comp(vec, 21, 52);
    comp(vec, 23, 54);
    comp(vec, 25, 56);
    comp(vec, 27, 58);
    comp(vec, 29, 60);
    comp(vec, 31, 62);
    comp(vec, 33, 64);
    comp(vec, 35, 66);
    comp(vec, 37, 68);
    comp(vec, 39, 70);
    comp(vec, 25, 40);
    comp(vec, 27, 42);
    comp(vec, 29, 44);
    comp(vec, 31, 46);
    comp(vec, 33, 48);
    comp(vec, 35, 50);
    comp(vec, 37, 52);
    comp(vec, 39, 54);
    comp(vec, 33, 40);
    comp(vec, 35, 42);
    comp(vec, 37, 44);
    comp(vec, 39, 46);
    comp(vec, 37, 40);
    comp(vec, 39, 42);
    comp(vec, 39, 40);
}

void sorting_network_bench(void)
{

    int8_t *data = static_cast<int8_t *>(calloc(sizeof(int8_t), num_elem * size_elem));

    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    // 0以上9以下の値を等確率で発生させる
    std::uniform_int_distribution<> dist(0, 255);

    //データ生成
    for (int i = 0; i < num_elem * size_elem; i++)
    {
        data[i] = dist(engine);
    }

    std::chrono::system_clock::time_point start, end; // 型は auto で可
    start = std::chrono::system_clock::now();         // 計測開始時間
#ifdef OPENMP
#pragma omp parallel for
#endif
    for (int i = 0; i < num_elem; i++)
    {
        sorter(data + i);
    }
    end = std::chrono::system_clock::now(); // 計測開始時間

    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "sorintg network[ms]\t" << elapsed << endl;
}

void std_sort_bench(void)
{
    int8_t *data = static_cast<int8_t *>(calloc(sizeof(int8_t), num_elem * size_elem));

    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    // 0以上9以下の値を等確率で発生させる
    std::uniform_int_distribution<> dist(0, 255);

    //データ生成
    for (int i = 0; i < num_elem * size_elem; i++)
    {
        data[i] = dist(engine);
    }

    std::chrono::system_clock::time_point start, end; // 型は auto で可
    start = std::chrono::system_clock::now();         // 計測開始時間

#ifdef OPENMP
#pragma omp parallel for
#endif
    for (int i = 0; i < num_elem; i++)
    {
        std::sort(data + i, data + i + size_elem);
    }
    end = std::chrono::system_clock::now(); // 計測開始時間

    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "C++ STL sort[ms]\t" << elapsed << endl;
}

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void qsort_bench(void)
{
    int8_t *data = static_cast<int8_t *>(calloc(sizeof(int8_t), num_elem * size_elem));

    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    // 0以上9以下の値を等確率で発生させる
    std::uniform_int_distribution<> dist(0, 255);

    //データ生成
    for (int i = 0; i < num_elem * size_elem; i++)
    {
        data[i] = dist(engine);
    }

    std::chrono::system_clock::time_point start, end; // 型は auto で可
    start = std::chrono::system_clock::now();         // 計測開始時間

#ifdef OPENMP
#pragma omp parallel for
#endif
    for (int i = 0; i < num_elem; i++)
    {
        qsort(data, 10, sizeof(int8_t), compare_int);
    }
    end = std::chrono::system_clock::now(); // 計測開始時間

    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "C stdlib.h qsort[ms]\t" << elapsed << endl;
}

int main(int argc, char const *argv[])
{
    sorting_network_bench();
    std_sort_bench();
    qsort_bench();
    return 0;
}
