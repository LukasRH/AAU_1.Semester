#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {

  FILE *image_file;
  int i, j;
  int r, g, b;

  image_file = fopen("image-file-4.pnm", "wb"); 

  fputs("P6\n", image_file); 
  fputs("500 500\n", image_file);
  fputs("255\n", image_file);

  for(i = 0; i < 500; i++)
    for (j = 0; j < 500; j++){
      r = i % 256; g = j % 256; b = (sin(i & j) / 42) % 256;
      fputc(r, image_file);  fputc(g, image_file); fputc(b, image_file);
    }

  fclose(image_file);
  return 0;
}