 /*
 * Name: Matthew Matze
 * Date:11/21/13
 * Class: CSC-1710 Fall 2013
 * Location: 
 */

#include<stdlib.h>

#define IMAGE_MAX_SIZE 800

#define RED_BW_WEIGHT 0.3
#define GREEN_BW_WEIGHT 0.6
#define BLUE_BW_WEIGHT 0.1
#define MAXCOLOR 255


struct pixelType {
   unsigned char red;
   unsigned char green;
   unsigned char blue;
};

struct imageType {
   char magicNumber[3];
   char comment[256];
   int width, height;
   int maxColor;
   struct pixelType image[IMAGE_MAX_SIZE][IMAGE_MAX_SIZE];
};

/**************************************************
 *  * read_image - read a ppm type image from a file
 *   * pre-condition - in_file is a file pointer that has been established
 *    *                 img is an struct imageType pointer that points to a 
 *     *                 struct imageType which is empty (or can be overwritten)
 *      * post-condition - img is loaded with a ppm image
 *       *                  in_file is pointing at the end of the file
 *        */
void read_image(FILE *in_file, struct imageType *img);

/**************************************************
 *  * write_image- read a ppm type image from a file
 *   * pre-condition - out_file is a file pointer that has been established
 *    *                 img is an struct imageType pointer that points to an
 *     *                 struct imageType containing the information for a 
 *      *                 ppm type image 
 *       * post-condition - out_file is now pointing at the end of the file 
 *        */
void write_image(FILE *out_file, struct imageType *img);

/**************************************************
 *  * read_pixel - read one ppm type pixel at the next position in a file
 *   * pre-condition - in_file is a file pointer that has been established
 *    *                 and should be pointing to 3 chars representing on 
 *     *                 ppm type pixel in a file.
 *      *                 p is a struct pixelType pointer, pointing to where to store
 *       *                 the pixel read
 *        * post-condition - *p is loaded with a ppm type pixel
 *         *                 in_file is point at the end of the file
 *          */
void read_pixel(FILE *in_file, struct pixelType *p);


/**************************************************
 *  * write_pixel - write one ppm type pixel to the next position in a file
 *   * pre-condition - out_file is a file pointer that has been established
 *    *                 and should be pointing to the next location in the file
 *     *                 to store a pixel (3 chars)
 *      *                 p is a struct pixelType 
 *       * post-condition - out_file is now pointing to the next location to
 *        *                 store a pixel (unless EOF)
 *         */
void write_pixel(FILE *out_file, struct pixelType p);

/*************************************************
 *  * cvt_pixel_bw - convert a color pixel into a black and white pixel
 *   * pre-condition - orig_p contains a color ppm type pixel
 *    * poxt-condition - a black and white ppm type pixel is returned.
 *     */
struct pixelType cvt_pixel_bw(struct pixelType orig_p);

/*************************************************
 *  * cvt_pixel_n - convert a color image to its negative
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information for a pixel in a ppm (P6) type image
 *       * post-condition - orig_img is not altered
 *        *                  new_img contains the information for the negative of the original
 *         *                  image created from the orig_img
 *          */
struct pixelType cvt_pixel_n(struct pixelType orig_p);

/*************************************************
 *  * cvt_pixel_b - replace everything that is green with the background image 
 *   * pre-condition - orig_img is a pointer to an struct pixelType containing the
 *    *                 information for a pixel in a P6 image
 *     *                 sec_img is a pointer to an struct pixelType containing the
 *      *                 information for a pixel in a P6 image
 *       * post-condition - orig_img and second img are not altered
 *        *                  new_img contains the information for the original with 
 *         *                  the background image inside
 *          */
struct pixelType cvt_pixel_b(struct pixelType orig_p,struct pixelType second_p);

/*************************************************
 *  * cvt_bw - convert a color image to a black and white image
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information about a ppm (P6) type image
 *     *                 new_img is an struct imageType pointer that points to 
 *      *                 a struct imageType which is empty (or can be overwritten)
 *       * post-condition - orig_img is not altered
 *        *                  new_img contains the information for a black and white
 *         *                  image created from the orig_img
 *          */
void cvt_bw(struct imageType *orig_img, struct imageType *new_img);

/*************************************************
 *  * cvt_m - convert a color image to a black and white image
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information about a ppm (P6) type image
 *     *                 new_img is an struct imageType pointer that points to 
 *      *                 a struct imageType which is empty (or can be overwritten)
 *       * post-condition - orig_img is not altered
 *        *                  new_img contains the information for the mirror of the original
 *         *                  image created from the orig_img
 *          */
void cvt_m(struct imageType *orig_img, struct imageType *new_img);

/*************************************************
 *  * cvt_n - convert a image to its negative image
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information about a ppm (P6) type image
 *     *                 new_img is an struct imageType pointer that points to 
 *      *                 a struct imageType which is empty (or can be overwritten)
 *       * post-condition - orig_img is not altered
 *        *                  new_img contains the information for the negative of the original
 *         *                  image created from the orig_img
 *          */
void cvt_n(struct imageType *orig_img, struct imageType *new_img);
/*************************************************
 *  * cvt_d - blend two images together
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information about a ppm (P6) type image
 *     *                 second_img is a pointer to an struct imageType containing the
 *      *                 information about a ppm (P6) type image
 *       *                 new_img is an struct imageType pointer that points to 
 *        *                 a struct imageType which is empty (or can be overwritten)
 *         * post-condition - orig_img and second_img aren't altered
 *          *                  new_img contains the information for the negative of the original
 *           *                  image created from blending orig_img and second_img
 *            */
void cvt_d(struct imageType *orig_img, struct imageType *second_img, struct imageType *new_img);

/*************************************************
 *  * cvt_pixel_d - blend two images together
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information for a pixel in a ppm (P6) type image
 *     *                 second_img is a pointer to an struct imageType containing the
 *      *                 information for a pixel in a ppm (P6) type image
 *       *                 blend is a double that holds the blending value the user inputed 
 *        * post-condition - orig_img and second_img aren't altered
 *         *                  new_img contains the information for the blended version 
 *          *                  of the original image created from orig_img and second_img
 *           */
struct pixelType cvt_pixel_d(struct pixelType orig_img, struct pixelType second_img, double blend);
/*************************************************
 *  * cvt_b - show the background image
 *   * pre-condition - orig_img is a pointer to an struct imageType containing the
 *    *                 information about a ppm (P6) type image
 *     *                 second_img is a pointer to an struct imageType containing the
 *      *                 information about a ppm (P6) type image
 *       *                 new_img is an struct imageType pointer that points to 
 *        *                 a struct imageType which is empty (or can be overwritten)
 *         * post-condition - orig_img and second_img aren't altered
 *          *                  new_img contains the information for the original image
 *           *                  with its new background. 
 *            */
void cvt_b(struct imageType *orig_img, struct imageType *second_img, struct imageType *new_img);
