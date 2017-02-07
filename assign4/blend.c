/*   Name: Matthew Matze
 *   Date: 9-13-13
 *   Class: csc1710
 *   Location: The UC Learning Commons
*/
   #include<stdio.h>

   main(void)
{

   float red1,green1,blue1;
   float red2,green2,blue2;
   float ratio;
   int reda,greena,bluea;

   printf("Please enter in the first color code you want to blend ");
   scanf("%f %f %f", &red1, &green1, &blue1);

   printf("Please enter in the sencond color code you want to blend ");
   scanf("%f %f %f", &red2, &green2, &blue2);

   printf("Please enter the blending ratio ");
   scanf("%f", &ratio);

   printf("Pixel 1: Red=%0.f Green=%0.f Blue=%0.f\n", red1, green1, blue1);
   printf("Pixel 2: Red=%0.f Green=%0.f Blue=%0.f\n\n", red2, green2, blue2);
   printf("Factor: %.2f\n", ratio);

   reda=(((red1-red2)*ratio)+red2);
   greena=(((green1-green2)*ratio)+green2);
   bluea=(((blue1-blue2)*ratio)+blue2);

   printf("New Pixel: Red=%i Green=%i blue=%i\n",reda, greena, bluea);
   printf("Hex Code: %X%X%X\n",reda, greena, bluea);

   return 0;

}
