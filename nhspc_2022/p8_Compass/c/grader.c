#include "Compass.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define a(x, y) _a[C+x][C+y]
#define C 3500

static int _a[2 * C + 1][2 * C + 1] = {0};
static int tmp[2 * C + 1];
static int cnt = 0;
static int total_len = 0;
static int Q = 6000000;
static int L = 1000000000;
static int _sqrt(int x){
    int l = 1, r = x;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if((long long)mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}
static void wrong_answer(const char* msg){
    printf("Wrong Answer: %s\n", msg);
    exit(0);
}
static void check_range_col(int x, int y, int len){
    if(x < -C || C < x || y < -C || C < y || len <= 0 || C < y + len - 1)
        wrong_answer("invalid operation");
}
static void check_range_row(int x, int y, int len){
    if(x < -C || C < x || y < -C || C < y || len <= 0 || C < x + len - 1)
        wrong_answer("invalid operation");
}
static void check_counter(int len){
    cnt++;
    total_len += len;
    if(cnt > Q || total_len > L)
        wrong_answer("too many operations");
}
static void check_val(int x, int y, int val){
    if(a(x, y) != val)
        wrong_answer("wrong result");
}


void set_col(int x, int y, int len, int val){
    check_counter(len);
    if(val != 0 && val != 1) wrong_answer("invalid operation");
    check_range_col(x, y, len);
    for(int k = 0; k < len; k++) a(x, y + k) = val;
}
void set_row(int x, int y, int len, int val){
    check_counter(len);
    if(val != 0 && val != 1) wrong_answer("invalid operation");
    check_range_row(x, y, len);
    for(int k = 0; k < len; k++) a(x + k, y) = val;
}
void not_col(int x, int y, int xout, int yout, int len){
    check_counter(len);
    check_range_col(x, y, len);
    for(int k = 0; k < len; k++) a(xout, yout + k) = !a(x, y + k);
}
void not_row(int x, int y, int xout, int yout, int len){
    check_counter(len);
    check_range_row(x, y, len);
    for(int k = 0; k < len; k++) a(xout + k, yout) = !a(x + k, y);
}
void and_col(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_col(x1, y1, len);
    check_range_col(x2, y2, len);
    check_range_col(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1, y1 + k) && a(x2, y2 + k);
    for(int k = 0; k < len; k++) a(xout, yout + k) = tmp[k];
}
void and_row(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_row(x1, y1, len);
    check_range_row(x2, y2, len);
    check_range_row(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1 + k, y1) && a(x2 + k, y2);
    for(int k = 0; k < len; k++) a(xout + k, yout) = tmp[k];
}
void or_col(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_col(x1, y1, len);
    check_range_col(x2, y2, len);
    check_range_col(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1, y1 + k) || a(x2, y2 + k);
    for(int k = 0; k < len; k++) a(xout, yout + k) = tmp[k];
}
void or_row(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_row(x1, y1, len);
    check_range_row(x2, y2, len);
    check_range_row(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1 + k, y1) || a(x2 + k, y2);
    for(int k = 0; k < len; k++) a(xout + k, yout) = tmp[k];
}
void xor_col(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_col(x1, y1, len);
    check_range_col(x2, y2, len);
    check_range_col(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1, y1 + k) ^ a(x2, y2 + k);
    for(int k = 0; k < len; k++) a(xout, yout + k) = tmp[k];
}
void xor_row(int x1, int y1, int x2, int y2, int xout, int yout, int len){
    check_counter(len);
    check_range_row(x1, y1, len);
    check_range_row(x2, y2, len);
    check_range_row(xout, yout, len);
    for(int k = 0; k < len; k++) tmp[k] = a(x1 + k, y1) ^ a(x2 + k, y2);
    for(int k = 0; k < len; k++) a(xout + k, yout) = tmp[k];
}

void debug(int x, int y){
    check_range_row(x, y, 1);
    printf("debug (%d,%d): %d\n", x, y, a(x, y));
}

int main(){
    long long r;
    assert(1 == scanf("%lld", &r));

    a(r, 0) = 1;

    draw_circle();

    for(int x = 0; x * x <= r * r - x * x; x++){
        int y = _sqrt(r * r - x * x);
        check_val(x, y, 1);
        check_val(-x, y, 1);
        check_val(-x, -y, 1);
        check_val(x, -y, 1);
        check_val(y, x, 1);
        check_val(-y, x, 1);
        check_val(-y, -x, 1);
        check_val(y, -x, 1);
        a(x, y) = a(-x, y) = a(-x, -y) = a(x, -y) = 0;
        a(y, x) = a(-y, x) = a(-y, -x) = a(y, -x) = 0;
    }

    for(int x = -C; x <= C; x++){
        for(int y = -C; y <= C; y++){
            check_val(x, y, 0);
        }
    }
    printf("Accepted: %d\n", cnt);
}
