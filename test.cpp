void foo(int i) {
    unsigned char char_array_3[3];
    int j = 0;
    if(i) {
        for (j = i; j < 3; j++) 
            char_array_3[j] = '\0'; 
    }
}


void test(int i) {
    int32_t c[6] = {0};
    c[5] = 1;
}
