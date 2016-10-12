#include <stdio.h>

int main(void) {

  FILE *image_file;
  int row, col;

  image_file = fopen("Danebro.pnm", "wb"); 

  fputs("P6\n", image_file); 
  fputs("500 500\n", image_file);
  fputs("255\n", image_file);

  for(row = 0; row < 500; row++)
    for (col = 0; col < 500; col++){
			if ((col <= 200 && row <= 225)||(col >= 250 && row <= 225) || (col <= 200 && row >= 275)||(col >= 250 && row >= 275))
			{
				fputc(255, image_file);  fputc(0, image_file); fputc(0, image_file);
			} else
			{
				fputc(255, image_file);  fputc(255, image_file); fputc(255, image_file);
			}
    }
  fclose(image_file);
  return 0;
}

