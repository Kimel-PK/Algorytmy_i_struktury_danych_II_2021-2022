#include <queue>
#include "ADTgraph.hpp"
#include "Skoczek.hpp"

using namespace std;

int main () {
	
	ADTgraph graf;
	
	graf.addVertex (1); // A1
	graf.addVertex (2); // A2
	graf.addVertex (3); // A3
	graf.addVertex (4); // A4
	graf.addVertex (5); // A5
	graf.addVertex (6); // A6
	graf.addVertex (7); // A7
	graf.addVertex (8); // A8
	graf.addVertex (9); // B1
	graf.addVertex (10); // B2
	graf.addVertex (11); // B3
	graf.addVertex (12); // B4
	graf.addVertex (13); // B5
	graf.addVertex (14); // B6
	graf.addVertex (15); // B7
	graf.addVertex (16); // B8
	graf.addVertex (17); // C1
	graf.addVertex (18); // C2
	graf.addVertex (19); // C3
	graf.addVertex (20); // C4
	graf.addVertex (21); // C5
	graf.addVertex (22); // C6
	graf.addVertex (23); // C7
	graf.addVertex (24); // C8
	graf.addVertex (25); // D1
	graf.addVertex (26); // D2
	graf.addVertex (27); // D3
	graf.addVertex (28); // D4
	graf.addVertex (29); // D5
	graf.addVertex (30); // D6
	graf.addVertex (31); // D7
	graf.addVertex (32); // D8
	graf.addVertex (33); // E1
	graf.addVertex (34); // E2
	graf.addVertex (35); // E3
	graf.addVertex (36); // E4
	graf.addVertex (37); // E5
	graf.addVertex (38); // E6
	graf.addVertex (39); // E7
	graf.addVertex (40); // E8
	graf.addVertex (41); // F1
	graf.addVertex (42); // F2
	graf.addVertex (43); // F3
	graf.addVertex (44); // F4
	graf.addVertex (45); // F5
	graf.addVertex (46); // F6
	graf.addVertex (47); // F7
	graf.addVertex (48); // F8
	graf.addVertex (49); // G1
	graf.addVertex (50); // G2
	graf.addVertex (51); // G3
	graf.addVertex (52); // G4
	graf.addVertex (53); // G5
	graf.addVertex (54); // G6
	graf.addVertex (55); // G7
	graf.addVertex (56); // G8
	graf.addVertex (57); // H1
	graf.addVertex (58); // H2
	graf.addVertex (59); // H3
	graf.addVertex (60); // H4
	graf.addVertex (61); // H5
	graf.addVertex (62); // H6
	graf.addVertex (63); // H7
	graf.addVertex (64); // H8
	
	graf.addEdge (1, 18);
	graf.addEdge (1, 11);
	graf.addEdge (2, 19);
	graf.addEdge (2, 12);
	graf.addEdge (3, 20);
	graf.addEdge (3, 13);
	graf.addEdge (3, 9);
	graf.addEdge (4, 21);
	graf.addEdge (4, 14);
	graf.addEdge (4, 10);
	graf.addEdge (5, 22);
	graf.addEdge (5, 15);
	graf.addEdge (5, 11);
	graf.addEdge (6, 23);
	graf.addEdge (6, 16);
	graf.addEdge (6, 12);
	graf.addEdge (7, 24);
	graf.addEdge (7, 13);
	graf.addEdge (8, 90);
	graf.addEdge (8, 14);
	graf.addEdge (9, 26);
	graf.addEdge (9, 19);
	graf.addEdge (9, 3);
	graf.addEdge (10, 27);
	graf.addEdge (10, 20);
	graf.addEdge (10, 4);
	graf.addEdge (11, 28);
	graf.addEdge (11, 21);
	graf.addEdge (11, 5);
	graf.addEdge (11, 17);
	graf.addEdge (11, 1);
	graf.addEdge (12, 29);
	graf.addEdge (12, 22);
	graf.addEdge (12, 6);
	graf.addEdge (12, 18);
	graf.addEdge (12, 2);
	graf.addEdge (13, 30);
	graf.addEdge (13, 23);
	graf.addEdge (13, 7);
	graf.addEdge (13, 19);
	graf.addEdge (13, 3);
	graf.addEdge (14, 31);
	graf.addEdge (14, 24);
	graf.addEdge (14, 8);
	graf.addEdge (14, 20);
	graf.addEdge (14, 4);
	graf.addEdge (15, 32);
	graf.addEdge (15, 21);
	graf.addEdge (15, 5);
	graf.addEdge (16, 170);
	graf.addEdge (16, 10);
	graf.addEdge (16, 22);
	graf.addEdge (16, 6);
	graf.addEdge (17, 34);
	graf.addEdge (17, 27);
	graf.addEdge (17, 11);
	graf.addEdge (17, 2);
	graf.addEdge (18, 35);
	graf.addEdge (18, 28);
	graf.addEdge (18, 12);
	graf.addEdge (18, 1);
	graf.addEdge (18, 3);
	graf.addEdge (19, 36);
	graf.addEdge (19, 29);
	graf.addEdge (19, 13);
	graf.addEdge (19, 25);
	graf.addEdge (19, 9);
	graf.addEdge (19, 2);
	graf.addEdge (19, 4);
	graf.addEdge (20, 37);
	graf.addEdge (20, 30);
	graf.addEdge (20, 14);
	graf.addEdge (20, 26);
	graf.addEdge (20, 10);
	graf.addEdge (20, 3);
	graf.addEdge (20, 5);
	graf.addEdge (21, 38);
	graf.addEdge (21, 31);
	graf.addEdge (21, 15);
	graf.addEdge (21, 27);
	graf.addEdge (21, 11);
	graf.addEdge (21, 4);
	graf.addEdge (21, 6);
	graf.addEdge (22, 39);
	graf.addEdge (22, 32);
	graf.addEdge (22, 16);
	graf.addEdge (22, 28);
	graf.addEdge (22, 12);
	graf.addEdge (22, 5);
	graf.addEdge (22, 7);
	graf.addEdge (23, 40);
	graf.addEdge (23, 29);
	graf.addEdge (23, 13);
	graf.addEdge (23, 6);
	graf.addEdge (23, 8);
	graf.addEdge (24, 90);
	graf.addEdge (24, 30);
	graf.addEdge (24, 14);
	graf.addEdge (24, 7);
	graf.addEdge (25, 42);
	graf.addEdge (25, 35);
	graf.addEdge (25, 19);
	graf.addEdge (25, 10);
	graf.addEdge (26, 43);
	graf.addEdge (26, 36);
	graf.addEdge (26, 20);
	graf.addEdge (26, 9);
	graf.addEdge (26, 11);
	graf.addEdge (27, 44);
	graf.addEdge (27, 37);
	graf.addEdge (27, 21);
	graf.addEdge (27, 33);
	graf.addEdge (27, 17);
	graf.addEdge (27, 10);
	graf.addEdge (27, 12);
	graf.addEdge (28, 45);
	graf.addEdge (28, 38);
	graf.addEdge (28, 22);
	graf.addEdge (28, 34);
	graf.addEdge (28, 18);
	graf.addEdge (28, 11);
	graf.addEdge (28, 13);
	graf.addEdge (29, 46);
	graf.addEdge (29, 39);
	graf.addEdge (29, 23);
	graf.addEdge (29, 35);
	graf.addEdge (29, 19);
	graf.addEdge (29, 12);
	graf.addEdge (29, 14);
	graf.addEdge (30, 47);
	graf.addEdge (30, 40);
	graf.addEdge (30, 24);
	graf.addEdge (30, 36);
	graf.addEdge (30, 20);
	graf.addEdge (30, 13);
	graf.addEdge (30, 15);
	graf.addEdge (31, 48);
	graf.addEdge (31, 37);
	graf.addEdge (31, 21);
	graf.addEdge (31, 14);
	graf.addEdge (31, 16);
	graf.addEdge (32, 38);
	graf.addEdge (32, 22);
	graf.addEdge (32, 15);
	graf.addEdge (33, 50);
	graf.addEdge (33, 43);
	graf.addEdge (33, 27);
	graf.addEdge (33, 18);
	graf.addEdge (34, 51);
	graf.addEdge (34, 44);
	graf.addEdge (34, 28);
	graf.addEdge (34, 17);
	graf.addEdge (34, 19);
	graf.addEdge (35, 52);
	graf.addEdge (35, 45);
	graf.addEdge (35, 29);
	graf.addEdge (35, 41);
	graf.addEdge (35, 25);
	graf.addEdge (35, 18);
	graf.addEdge (35, 20);
	graf.addEdge (36, 53);
	graf.addEdge (36, 46);
	graf.addEdge (36, 30);
	graf.addEdge (36, 42);
	graf.addEdge (36, 26);
	graf.addEdge (36, 19);
	graf.addEdge (36, 21);
	graf.addEdge (37, 54);
	graf.addEdge (37, 47);
	graf.addEdge (37, 31);
	graf.addEdge (37, 43);
	graf.addEdge (37, 27);
	graf.addEdge (37, 20);
	graf.addEdge (37, 22);
	graf.addEdge (38, 55);
	graf.addEdge (38, 48);
	graf.addEdge (38, 32);
	graf.addEdge (38, 44);
	graf.addEdge (38, 28);
	graf.addEdge (38, 21);
	graf.addEdge (38, 23);
	graf.addEdge (39, 56);
	graf.addEdge (39, 45);
	graf.addEdge (39, 29);
	graf.addEdge (39, 22);
	graf.addEdge (39, 24);
	graf.addEdge (40, 46);
	graf.addEdge (40, 30);
	graf.addEdge (40, 23);
	graf.addEdge (41, 58);
	graf.addEdge (41, 51);
	graf.addEdge (41, 35);
	graf.addEdge (41, 26);
	graf.addEdge (42, 59);
	graf.addEdge (42, 52);
	graf.addEdge (42, 36);
	graf.addEdge (42, 25);
	graf.addEdge (42, 27);
	graf.addEdge (43, 60);
	graf.addEdge (43, 53);
	graf.addEdge (43, 37);
	graf.addEdge (43, 49);
	graf.addEdge (43, 33);
	graf.addEdge (43, 26);
	graf.addEdge (43, 28);
	graf.addEdge (44, 61);
	graf.addEdge (44, 54);
	graf.addEdge (44, 38);
	graf.addEdge (44, 50);
	graf.addEdge (44, 34);
	graf.addEdge (44, 27);
	graf.addEdge (44, 29);
	graf.addEdge (45, 62);
	graf.addEdge (45, 55);
	graf.addEdge (45, 39);
	graf.addEdge (45, 51);
	graf.addEdge (45, 35);
	graf.addEdge (45, 28);
	graf.addEdge (45, 30);
	graf.addEdge (46, 63);
	graf.addEdge (46, 56);
	graf.addEdge (46, 40);
	graf.addEdge (46, 52);
	graf.addEdge (46, 36);
	graf.addEdge (46, 29);
	graf.addEdge (46, 31);
	graf.addEdge (47, 64);
	graf.addEdge (47, 53);
	graf.addEdge (47, 37);
	graf.addEdge (47, 30);
	graf.addEdge (47, 32);
	graf.addEdge (48, 54);
	graf.addEdge (48, 38);
	graf.addEdge (48, 31);
	graf.addEdge (49, 59);
	graf.addEdge (49, 43);
	graf.addEdge (49, 34);
	graf.addEdge (50, 60);
	graf.addEdge (50, 44);
	graf.addEdge (50, 33);
	graf.addEdge (50, 35);
	graf.addEdge (51, 61);
	graf.addEdge (51, 45);
	graf.addEdge (51, 57);
	graf.addEdge (51, 41);
	graf.addEdge (51, 34);
	graf.addEdge (51, 36);
	graf.addEdge (52, 62);
	graf.addEdge (52, 46);
	graf.addEdge (52, 58);
	graf.addEdge (52, 42);
	graf.addEdge (52, 35);
	graf.addEdge (52, 37);
	graf.addEdge (53, 63);
	graf.addEdge (53, 47);
	graf.addEdge (53, 59);
	graf.addEdge (53, 43);
	graf.addEdge (53, 36);
	graf.addEdge (53, 38);
	graf.addEdge (54, 64);
	graf.addEdge (54, 48);
	graf.addEdge (54, 60);
	graf.addEdge (54, 44);
	graf.addEdge (54, 37);
	graf.addEdge (54, 39);
	graf.addEdge (55, 61);
	graf.addEdge (55, 45);
	graf.addEdge (55, 38);
	graf.addEdge (55, 40);
	graf.addEdge (56, 62);
	graf.addEdge (56, 46);
	graf.addEdge (56, 39);
	graf.addEdge (57, 51);
	graf.addEdge (57, 42);
	graf.addEdge (58, 52);
	graf.addEdge (58, 41);
	graf.addEdge (58, 43);
	graf.addEdge (59, 53);
	graf.addEdge (59, 49);
	graf.addEdge (59, 42);
	graf.addEdge (59, 44);
	graf.addEdge (60, 54);
	graf.addEdge (60, 50);
	graf.addEdge (60, 43);
	graf.addEdge (60, 45);
	graf.addEdge (61, 55);
	graf.addEdge (61, 51);
	graf.addEdge (61, 44);
	graf.addEdge (61, 46);
	graf.addEdge (62, 56);
	graf.addEdge (62, 52);
	graf.addEdge (62, 45);
	graf.addEdge (62, 47);
	graf.addEdge (63, 53);
	graf.addEdge (63, 46);
	graf.addEdge (63, 48);
	graf.addEdge (64, 54);
	graf.addEdge (64, 47);
	
	std::queue<Skoczek> konie;
	konie.push (Skoczek(1));
	
	int i = 0;
	
	while (konie.size() > 0) {
		Skoczek kon = konie.front ();
		
		for (ADTgraph::Edge edge : graf.neighbours (kon.obecnePole)) {
			if (!kon.CzyOdwiedzono (edge.end_node)) {
				Skoczek kon2 = kon;
				kon2.OdwiedźPole (edge.end_node);
				konie.push (kon2);
			}
		}
		
		konie.pop ();
		i++;
		if (i % 1000000 == 0) {
			cout << "ilość koni: " << konie.size() << endl;
			cout << "losowy koń odwiedził: " << konie.front().odwiedzonePola.size() << endl;
		}
	}
	
}