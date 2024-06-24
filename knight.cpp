#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <algorithm>
#include <vector>
#include <ctime>
#define CBX 8
#define CBY 8

using namespace std;

int main() {
	int cb[CBX][CBY] = {};
	int dx[CBX] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int dy[CBY] = {1, 2, 2, 1, -1, -2, -2, -1};

	srand ( time(NULL) );
	int kx = rand() % CBX;
	int ky = rand() % CBY;

	vector<int> pq;
	vector<int> idx;

	int nx;
	int ny;

	int ex;
	int ey;

	int ctr;

	int min;
	int imin;

	int i, j, k, cy, cx;

	ofstream log;

	log.open("log-cpp.log");

	log << "initial knight's position is at (" << kx << ", " << ky << ")\n"; 

	clock_t start = clock();

	for(k = 0; k < CBX * CBY; k++) {
		cb[ky][kx] = k + 1;
		log << "move to (" << ky << ", " << kx << ")\n";
		pq.clear();
		idx.clear();
		for(i = 0; i < CBX; i++) {
			nx = kx + dx[i];
			ny = ky + dy[i];
			if((nx >= 0 && nx < CBX) && (ny >=0 && ny < CBY)) {
				if(cb[ny][nx] == 0) {
					log << "check to (" << ny << ", " << nx << ")\n";
					ctr = 0;
					for(int j = 0; j < CBY; j++) {
						ex = nx + dx[j];
						ey = ny + dy[j];
						if((ex >= 0 && ex < CBX) && (ey >= 0 && ey < CBY)) {
							if(cb[ey][ex] == 0) {
								ctr++;
								log << "coordinate (" << ey << ", " << ex << ") is available\n";
							} else {
								log << "coordinate (" << ey << ", " << ex << ") is not available\n";
							}
						} else {
							log << "coordinate (" << ey << ", " << ex << ") is offside\n";
						}
					}
					log << "on (" << ny << ", " << nx << ") ctr is " << ctr << "\n";
					pq.push_back(ctr);
					idx.push_back(i);
				} else {
					log << "coordinate (" << ny << ", " << nx << ") is not available\n";
				}
			} else {
				log << "coordinate (" << ny << ", " << nx << ") is offside\n";
			} 
		}
		if (!pq.empty()){
			log << "check minimum counter\n";
			for(int it = 0; it != pq.size(); it++) {
				if(it == 0) {
					min = pq[it];
					imin = it;
					// log << pq[it] << " " << it << endl;
				} else {
					if(pq[it] < min) {
						min = pq[it];
						imin = it;
						// log << pq[it] << " " << it << endl;
					}
				}
			}
			log << "minimum value is " << min << " in index " << imin << endl;
			kx += dx[idx[imin]];
			ky += dy[idx[imin]];
		}
		else {
			log << "no available move\n";
			break;
		}
	}

	clock_t end = clock();

	for(cy = 0; cy < CBY; cy++) {
		for(cx = 0; cx < CBX; cx++) {
			cout << cb[cy][cx] << " ";
			log << cb[cy][cx] << " ";
		}
		cout << "\n";
		log << "\n";
	}

	clock_t duration = end - start;

	cout << "execution time : " << (float)duration / CLOCKS_PER_SEC << " sec" << endl;

	log << "execution time : " << (float)duration / CLOCKS_PER_SEC << " sec" << endl;
	
	log.close();

	return 0;  
}
