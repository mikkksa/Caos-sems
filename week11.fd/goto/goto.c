int main() {
    volatile int i = 0;
    while(1) {
        i++;
	if (i == 57) {
            goto end;
	}
    }
end:
    return 0;
}
