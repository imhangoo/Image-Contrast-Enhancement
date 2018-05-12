#ifndef HIST_EQU_COLOR_H
#define HIST_EQU_COLOR_H

#define BLOCK_SIZE 1024

typedef struct{
    int w;
    int h;
    unsigned char * img;
} PGM_IMG;    

typedef struct{
    int w;
    int h;
    unsigned char * img_r;
    unsigned char * img_g;
    unsigned char * img_b;
} PPM_IMG;

typedef struct{
    int w;
    int h;
    unsigned char * img_y;
    unsigned char * img_u;
    unsigned char * img_v;
} YUV_IMG;


typedef struct
{
    int width;
    int height;
    float * h;
    float * s;
    unsigned char * l;
} HSL_IMG;


PPM_IMG read_ppm(const char * path);
void write_ppm(PPM_IMG img, const char * path);
void free_ppm(PPM_IMG img);

PGM_IMG read_pgm(const char * path);
void write_pgm(PGM_IMG img, const char * path);
void free_pgm(PGM_IMG img);

HSL_IMG rgb2hsl(PPM_IMG img_in);
PPM_IMG hsl2rgb(HSL_IMG img_in);

YUV_IMG rgb2yuv(PPM_IMG img_in);
PPM_IMG yuv2rgb(YUV_IMG img_in);    

void histogram(int * hist_out, unsigned char * img_in, int img_size, int nbr_bin);
void histogram_equalization(unsigned char * img_out, unsigned char * img_in, 
                            int * hist_in, int img_size, int nbr_bin);

//Contrast enhancement for gray-scale images
PGM_IMG contrast_enhancement_g(PGM_IMG img_in);

//Contrast enhancement for color images
PPM_IMG contrast_enhancement_c_rgb(PPM_IMG img_in);
PPM_IMG contrast_enhancement_c_yuv(PPM_IMG img_in);
PPM_IMG contrast_enhancement_c_hsl(PPM_IMG img_in);


// gpu functions

HSL_IMG rgb2hsl_gpu(PPM_IMG img_in);
PPM_IMG hsl2rgb_gpu(HSL_IMG img_in);

YUV_IMG rgb2yuv_gpu(PPM_IMG img_in);
PPM_IMG yuv2rgb_gpu(YUV_IMG img_in);    

void histogram_gpu(int * hist_out, unsigned char * img_in, int img_size, int nbr_bin);
void histogram_equalization_gpu(unsigned char * img_out, unsigned char * img_in, 
                            int * hist_in, int img_size, int nbr_bin);

//Contrast enhancement for gray-scale images
PGM_IMG contrast_enhancement_g_gpu(PGM_IMG img_in);

//Contrast enhancement for color images
PPM_IMG contrast_enhancement_c_rgb_gpu(PPM_IMG img_in);
PPM_IMG contrast_enhancement_c_yuv_gpu(PPM_IMG img_in);
PPM_IMG contrast_enhancement_c_hsl_gpu(PPM_IMG img_in);


#endif