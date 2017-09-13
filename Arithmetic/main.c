#include <stdio.h>
#include<stdlib.h>
#include <stdint.h>
#define K 8
#define BITSIZE 255000
long high = 0, low = 0, range = 0, ub = 0,code = 0;
FILE * writeFile = NULL;
FILE * readFile = NULL;
FILE * tempFile = NULL;
int bits[100];
int cnt = 0;
int leftBits = 0;
unsigned int buf = 0;
int garbage_bits = 0;
void init(){
    high = (1 << K) - 1;
    low = 0;
    ub = 0;
    range = 0;
    cnt = 0;
}
void startPutBits(){
    leftBits = 32;
    buf = 0;
}
void startGetBits(){
    garbage_bits = 0;
    leftBits = 0;
    buf = 0;
}
void flushBit(){
    unsigned int mark = 1 << (K-2);
    int bit = !!(low & mark);
    putBit(bit);
    ub = ub + 1;
    bit = bit == 0 ? 1 : 0;
    while(ub){
        putBit(bit);
        ub = ub - 1;
    }
}
void putBit(int bit){
    buf >>= 1;                               /* Put bit in top of buffer.*/
    if (bit) buf |= 0x80000000;
    leftBits -= 1;
    if (leftBits==0) {                        /* Output buffer if it is   */
        fprintf(tempFile,"%d",buf);                    /* now full.                */
        leftBits = 32;
    }
}
void endPutBits(){
    fprintf(tempFile,"%d",buf>>leftBits);
}
int getBit(){
    int t;
    if (leftBits==0) {                        /* Read the next byte if no */
        fscanf(tempFile,"%d",&buf);                   /* bits are left in buffer. */
        if (buf==EOF) {
            garbage_bits += 1;                      /* Return arbitrary bits*/
            if (garbage_bits> K -2) {   /* after eof, but check */
                fprintf(stderr,"Bad input file/n"); /* for too many such.   */
                exit(-1);
            }
        }
        leftBits = 32;
    }
    t = buf & 1;                               /* Return the next bit from */
    buf >>= 1;                               /* the bottom of the byte. */
    leftBits -= 1;
    return t;
}
void putN(int x,int N){
    int sc = N+1;
    int lc = x;
    int hc = x + 1;
    encodeSymbol(lc,hc,sc);
}
int getN(int N){
    range = high - low + 1;
    int sc = N + 1;
    int x = ((code-low+1)*sc-1 )/range;
    int hc= x + 1;
    int lc= x;
    decodeSymbol(hc,sc,lc);//RemoveSymbol;
    return x;
}

void encodeSymbol(int lc,int hc,int sc){
    range = (long)(high - low) + 1;
    high = low + range  * hc / sc - 1;
    low = low + range * lc / sc;
    unsigned int mark = 0xfffffeff;
    unsigned int mark2 = 1 <<(K-1);
    unsigned int mark3 = 1 <<(K-2);
    while(1){
        if(!!(high & mark2) == !!(low & mark2)){
            putBit(!!(high & mark2));
            while(ub > 0){
                if(!!(high & mark2)){
                    putBit(0);
                }else{
                    putBit(1);
                }
                ub = ub - 1;
            }
        }else if((!!(low & mark3)) & ((!!(high & mark3)) == 0 ? 1 : 0)){
            ub = ub + 1;
            low = (low ^ mark3);
            high = (high ^ mark3);
        }else{
            break;
        }
        low  = (low << 1) & mark;
        high = ((high << 1) + 1) & mark;
    }
}
void decodeSymbol(int hc,int sc,int lc){
    range = high - low + 1;
    high = low + (range * hc)/sc-1;
    low = low + (range * lc)/sc;
    unsigned int mark = 0xfffffeff;
    unsigned int mark2 = 1 << (K-1);
    unsigned int mark3 = 1 << (K-2);
    while(1){
        if( !!(high & mark2) == !!(low & mark2)){
        }else if(!!(low & mark3) & ((!!(high & mark3)) == 0 ? 1 : 0)){
            code = code ^ mark3;
            low = (low ^ mark3);
            high = (high ^ mark3);
        }else{
            break;
        }
        low  = (low << 1) & mark;
        high = ((high << 1) + 1) & mark;
        code = ((code << 1) + getBit()) & mark;//code = (code << 1 + getBit()) ^ mark; 本来置为0的是这种写法。但是这样子是不行的。
    }

}
void putS(int x,int s[3],int c[3],int size){
    int lc = 0, hc = 0, sc = 0,sum = 0,m = 0;
    for(int i = 1; i < size; i++){
        sc += c[i];
        if(x == s[i]){
            m = i;
        }
    }
    for(int i = 1; i <= m; i++){
        sum += c[i];
    }
    lc = sc - sum;
    hc = lc + c[m];
    encodeSymbol(lc,hc,sc);
}
int getS(int s[3],int c[3]){
    range = high - low + 1;
    int sc = c[1]+c[2];
    int count = (((code-low+1)*sc-1)/range);
    int m=1;
    int lc=sc-c[1];
    while (lc>count){
        m=m+1;
        lc=lc-c[m];
    }
    int hc=lc+c[m];
    decodeSymbol(hc,sc,lc);
    return s[m];
}
void encodeBin(int x[],int L){
    int oneCount = 0, zeroCount = 0;
    int n1 = 0, n0 = 0;
    int s[3] = {0,0,1};
    int c[3] = {0};
    for(int i = 1; i < L; i++){
        if(x[i] == 1){
            oneCount++;
        }else{
            zeroCount++;
        }
    }
    n1 = oneCount + x[L];
    n0 = L - n1;
    putN(n1,L);

    for(int i = 1; i <= L; i++){
        if(~(n0 * n1) == 1){//这里不知道matlab的意思是不是n0 和n1 其中有一个等于0；
            break;
        }
        c[1] = n0;
        c[2] = n1;
        putS(x[i],s,c,3);
        n0 = n0 - 1 + x[i];
        n1 = n1 - x[i];
    }

}

void decodeBin(int L){
    int n1 = getN(L);
    int n0= L- n1;
    int s[3] = {0,0,1};
    int c[3] = {0};
    int x = 0;
    for(int i = 1; i <= L; i++){
        if(n0 == 0){
            for(int j = i; j <= L; j++){
                fprintf(writeFile,"%d  ",1);
            }
            break;
        }
        if(n1 == 0){
            fprintf(writeFile,"%d  ",0);
            break;
        }
        c[1] = n0;
        c[2] = n1;
        x = getS(s,c);
        fprintf(writeFile,"%d  ",x);
        n0 = n0 - 1 + x;
        n1 = n1 - x;
    }
}
void encode(){
    init();
    int bits[21];
    for(int i = 1; i <= 20; i++){
        fscanf(readFile,"%d",&bits[i]);
    }
    encodeBin(bits,20);
}
void decode(){
    init();
    cnt = 0;
    for(int i = 0; i < K; i++){
        code = (code << 1) + getBit();
    }
    decodeBin(20);

}

int main() {
    readFile = fopen("readFile.txt","r");
    writeFile = fopen("writeFile.txt","w");
    tempFile = fopen("tempFile.txt","w");
    if(writeFile == NULL || readFile == NULL || tempFile == NULL){
        printf("open the writeFile or readFile failure\n");
    }
    int *buffer = (int *)malloc(sizeof(int)*BITSIZE);
    int buf = 0;
    startPutBits();
    encode();
    flushBit();
    endPutBits();
    fclose(tempFile);
    printf("use %d bits",cnt);
    tempFile = fopen("tempFile.txt","r");
    if(tempFile == NULL){
        printf("open the file failure\n");
    }
    startGetBits();
    decode();
    fclose(tempFile);

    return 0;
}