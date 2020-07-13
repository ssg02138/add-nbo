#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

void dump(void* p, size_t n) {	// Ư�� �޸� ��ġ�� ���������ִ� �Լ�
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

void write_4660() {
	uint16_t port = 4660; // uint16_t(2byte), 0x1234 -> �޸� 34 12 ���� (intel)
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

uint16_t my_ntohs(uint16_t n) {
	/*
	uint16_t n1 = (n & 0xFF00) >> 8; // 34 00 -> 00 34
	uint16_t n2 = (n & 0x00FF) << 8; // 00 12 -> 12 00
	return (n2 | n1); // 12 34
	*/
	return (n & 0xFF00) >> 8 | (n & 0x00FF) << 8;
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };// �޸� 34 12 ����
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	//uint16_t n = my_ntohs(*p); // TODO, 12 34 ����
	uint16_t n = ntohs(*p); // C �����Ϸ� �⺻ ���� �Լ�

	scanf("%hu", &a);
	uint16_t n2 = ntohs(a);
	printf("16 bit number=0x%x\n", n2);

	printf("16 bit number=0x%x\n", n);
}

uint32_t my_ntohl(uint32_t n) { // 12 34 56 78
	return (n & 0xFF000000) >> 24 | (n & 0x00FF0000) >> 8 | (n & 0x0000FF00) << 8 | (n & 0x000000FF) << 24;
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	//uint32_t n = my_ntohl(*p); // TODO
	uint16_t n = ntohl(*p); // C �����Ϸ� �⺻ ���� �Լ�, �򿣵���� ��쵵 ���� -> �����Ѱ� 34 12
	network_buffer = file_io();
	printf("32 bit number=0x%x\n", n);
}

void file_io() {
	FILE *fp ;
	int index;
	int data;
	uint8_t file_buffer[] = {0, 0, 0, 0};

	fp = fopen("file.txt", "r");
	int i = 0;
	while(fscanf(fp, "%x", &data) != EOF){
		file_buffer[i] = data;
		i++;
	}
	fclose(fp);
	
	return file_buffer;
}

int main() {
	//write_4660();
	//write_0x1234();
	write_0x12345678();
}
