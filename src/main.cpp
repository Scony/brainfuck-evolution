#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>

#include "Exception.hpp"
#include "Parser.hpp"
#include "Interpreter.hpp"
#include "Memory.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      Parser parser(argc,argv);
      Interpreter interpreter(parser.getParsedCode());
      interpreter.run();
      Memory * memory = interpreter.getMemory();

      memory->front();
      int width = memory->read();
      memory->next();
      int height = memory->read();

      if(width <= 0 || height <= 0)
      	throw new Exception("Width || height <= 0");

      IplImage * img = cvCreateImage(cvSize(width+100,height+100),IPL_DEPTH_32F,3);

      for(int i = 0; i < height+100; i++)
      	for(int j = 0; j < width+100; j++)
      	  {
      	    CvScalar px;

      	    for(int k = 0; k < 3; k++)
	      px.val[k] = 127;

      	    cvSet2D(img,i,j,px);
      	  }

      for(int i = 50; i < 50+height; i++)
      	for(int j = 50; j < 50+width; j++)
      	  {
      	    CvScalar px;

      	    for(int k = 2; k >= 0; k--)
      	      {
      		memory->next();
      		px.val[k] = memory->read();
      	      }

      	    cvSet2D(img,i,j,px);
      	  }

      cvNamedWindow("Bfgcv",CV_WINDOW_AUTOSIZE);
      cvShowImage("Bfgcv",img);

      cvWaitKey(0);

      cvDestroyWindow("Bfgcv");
      cvReleaseImage(&img);
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
