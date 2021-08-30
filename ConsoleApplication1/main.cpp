﻿#include <linux/i2c-dev.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <string>
#include <sys/ioctl.h>
//#include "json"
#include <linux/i2c-dev.h>
#include <json.h>

#define PACKETSIZE	32

using namespace std;

int openi2c(int slave_addr) {
	//----- OPEN THE I2C BUS -----
	char* filename = (char*)"/dev/i2c-1";
	int fd = open(filename, O_RDWR);
	if (fd < 0) { printf("Failed to open the i2c bus"); return fd; }

	int io = ioctl(fd, I2C_SLAVE, slave_addr);
	if (io < 0) printf("Failed to acquire bus access and/or talk to slave.\n");
	return fd;
}

int main(int argc, char* argv[]) {
	int fd = openi2c(0x28);
	if (fd < 0) {
		printf("Error in opening i2c. fd=%d\n", fd);
		return fd;
	}
	while (1) {
		// json 만들기

		// i2c 읽어오기
		unsigned char data[PACKETSIZE];
		int n = read(fd, data, PACKETSIZE);
		if (n != PACKETSIZE) { // 요청한 읽기 크기와 실제 읽어 온 크기 비교
			printf("Error in reading i2c. n=%d\n", n);
			return -1;
		}
		// 읽어온 값 Json 쓰기
		Json::Value root;
		root["Status"] = data[2];
		root["MeasuringMode"] = 256 * data[3] + data[4];
		root["CalibCoeff"] = 256 * data[5] + data[6];

		Json::Value grim;
		grim["PM0.1"] = 256 * data[7] + data[8];
		grim["PM2.5"] = 256 * data[9] + data[10];
		grim["PM10"] = 256 * data[11] + data[12];

		Json::Value tsi;
		tsi["PM0.1"] = 256 * data[13] + data[14];
		tsi["PM2.5"] = 256 * data[15] + data[16];
		tsi["PM10"] = 256 * data[17] + data[18];

		Json::Value dust;
		dust["2.5um"] = 256 * data[19] + data[20];
		dust["5.0um"] = 256 * data[21] + data[22];
		dust["10um"] = 256 * data[23] + data[24];
		dust["2.5um"] = 256 * data[25] + data[26];
		dust["5.0um"] = 256 * data[27] + data[28];
		dust["10um"] = 256 * data[29] + data[30];

		root["GRIMM"] = grim;
		root["TSI"] = tsi;
		root["Dust"] = dust;

		cout<<root.toStyledString();


		// 읽어 온 값 디스플레이
		printf("Status=%d, MeasuringMode=%d, CalibCoeff=%d\n", data[2], 256 * data[3] + data[4], 256 * data[5] + data[6]);
		printf("GRIM: PM0.1=%5d, PM2.5=%5d, PM10=%5d\n",
			256 * data[7] + data[8], 256 * data[9] + data[10], 256 * data[11] + data[12]);
		printf(" TSI: PM0.1=%5d, PM2.5=%5d, PM10=%5d\n",
			256 * data[13] + data[14], 256 * data[15] + data[16], 256 * data[17] + data[18]);
		printf("Dust: 0.3um=%5d, 0.5um=%5d,  1um=%5d\n",
			256 * data[19] + data[20], 256 * data[21] + data[22], 256 * data[23] + data[24]);
		printf("Dust: 2.5um=%5d, 5.0um=%5d, 10um=%5d\n",
			256 * data[25] + data[26], 256 * data[27] + data[28], 256 * data[29] + data[30]);
		sleep(2);
	}
	return 0;
}