void foo() {
    int array[10];
    int i = get();
    // i = 9;
    if (i > 8 && i <= length(array)) {  // Shoud be i < length(array)
        array[i] = 1;  // defect: array[10] overflow
    }
    array[i] = 1;  // defect: array[10] overflow
}


void test(int i) {
    int n= 10;
    char *p = malloc(sizeof(int) * 10);
    int y = n;
    p[y] = 'a'; // defect: writing to buffer[y] overflow
}

void increase1() {
    while (1) {
        mtx.lock();
        if (counter <= 1000)
            counter++;
        else
            break;
        read_counter(counter);  // defect: dead_lock
        mtx.unlock()
    }
}
void read_counter(counter){
    std::cout << counter << std::endl;
    do_something_more();
}
void increase1() {
    while (1) {
        std::lock_guard<std::mutex> lk(mtx);  // good: 使用lock_guard会自动上锁解锁将不会检查dead_lock
        if (counter <= 1000)
            counter++;
        else
            break;
        read_counter(counter);
    }
}
