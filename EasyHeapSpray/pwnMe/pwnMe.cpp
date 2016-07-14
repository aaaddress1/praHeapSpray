#include <Windows.h>
#include <stdio.h>
void bufferOverflow()
{
	char Buff[4];
	DWORD fileSize;
	printf("buffer begin at: %p\n", Buff);

	if (FILE* fIn = fopen("dataBuffer.txt", "r+")) {
		fseek(fIn, 0, SEEK_END);
		fileSize = ftell(fIn);
		rewind(fIn);
		fread(Buff,1,fileSize,fIn);
		fclose(fIn);
	}

}
void heapSpray()
{
	for (int i = 0; i < 5; i++) {
		if (FILE* fIn = fopen("dataSpray.txt", "r+")) {
			char *ptr = (char*)VirtualAlloc(0, 1024 * 1024, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			printf("current data at %p ~ %x\n", ptr, (DWORD)ptr + 1024 * 1024 - 1);
			fread(ptr,1,1024*1024,fIn );
			fclose(fIn);
		}
		else
			break;
	}
}
int main(void)
{
	puts("Easy Heap Spray PoC, By.aaaddress1@gmail.com");
	heapSpray();
	bufferOverflow();
	return 0;
}


