#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // a double loop that looks into the image and checks if the pixels are black then change them into red
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make black pixels turn red
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0xff;
            }
        }
    }
}