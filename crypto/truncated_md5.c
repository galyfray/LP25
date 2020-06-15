#include "crypto.h"

//fonction de hachage reprise du md5 modifié pour sortir une chaine de 8 charactères

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

char* truncated_md5(char *toHash, uint8_t offset,size_t initial_len, char *hashReturn)
{
    uint8_t *initial_msg = (uint8_t *) toHash;
    uint8_t h0,h1,h2,h3, *msg=NULL;
    uint8_t r[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
    uint8_t k[] = {
        0xd7, 0xe8, 0x24, 0xc,
        0xf5, 0x47, 0xa8, 0xfd,
        0x69, 0x8b, 0xff, 0x89,
        0x6b, 0xfd, 0xa6, 0x49,
        0xf6, 0xc0, 0x26, 0xe9,
        0xd6, 0x02, 0xd8, 0xe7,
        0x21, 0xc3, 0xf4, 0x45,
        0xa9, 0xfc, 0x67, 0x8d,
        0xff, 0x87, 0x6d, 0xfd,
        0xa4, 0x4b, 0xf6, 0xbe,
        0x28, 0xea, 0xd4, 0x04,
        0xd9, 0xe5, 0x1f, 0xc4,
        0xf4, 0x4f, 0xab, 0xfc,
        0x65, 0x8a, 0xff, 0x85,
        0x6f, 0xf2, 0xa3, 0x4e,
        0xf7, 0xb6, 0x2a, 0xeb};

    h0 = 0x67;
    h1 = 0xef;
    h2 = 0x98;
    h3 = 0x10;
int new_len;
    for(new_len = initial_len*8 + 1; new_len%512!=448; new_len++);
    new_len /= 8;

    msg = calloc(new_len + 64, 1); // also appends "0" bits
                                   // (we alloc also 64 extra bytes...)
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128; // write the "1" bit

    uint32_t bits_len = 8*initial_len; // note, we append the len
    memcpy(msg + new_len, &bits_len, 4);           // in bits at the end of the buffer

    // Process the message in successive 512-bit chunks:
    //for each 512-bit chunk of message:
    int offsetA;
    for(offsetA=0; offsetA<new_len; offsetA += (512/8)) {

        // break chunk into sixteen 32-bit words w[j], 0 ≤ j ≤ 15
        uint8_t *w = (uint8_t *) (msg + offsetA);


        // Initialize hash value for this chunk:
        uint8_t a = h0;
        uint8_t b = h1;
        uint8_t c = h2;
        uint8_t d = h3;

        // Main loop:
        uint32_t i;
        for(i = 0; i<64; i++) {


            uint8_t f, g;

             if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (offset*i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7*i) % 16;
            }


            uint8_t temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
            a = temp;



        }

        // Add this chunk's hash to result so far:

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;

    }

    sprintf(hashReturn,"%02x%02x%02x%02x",h0,h1,h2,h3);
    // cleanup
    free(msg);
    return hashReturn;
}
