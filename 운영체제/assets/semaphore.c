semaphore n = 0, s = 1;
void producer() {
    while (1) {
        produce(); //새로운 아이템 생성
        sem_wait(s); // 문 걸어 잠그기
        append(); //버퍼에 아이템 추가(critical section)
        sem_signal(s); // 문 풀어 열기
        sem_signal(n); // 아이템 개수 증가
    }
}

void consumer() {
    while (1) {
        sem_wait(n); // 아이템 개수 감소. n이 0이면 대기.
        sem_wait(s); // 문 걸어 잠그기
        take(); // 버퍼에서 아이템 제거(critical section)
        sem_signal(s); // 문 풀어 열기
        consume(); // 아이템 소비
    }
}
void main() {
    parbegin(producer, consumer);
}