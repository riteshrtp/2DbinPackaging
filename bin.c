#include<stdio.h>
struct items
{
  int binAllocated,width,height;
  int x1,x2,x3,x4,y1,y2,y3,y4;
};

int main()
{
  struct items item[100];
  int i=0,binWidth=0,binHeight=0,itemCount=0,binNumber=0,binWidthRemain=0,binHeightRemain=0,binWidthUsed=0,binHeightUsed=0,maxColWidth=0,colWidth=0;
  int xUsed=0,maxXUsed=0;
  printf("Enter the dimesion of bin W x H: ");
  scanf("%d %d",&binWidth,&binHeight);
  printf("\nEnter the number of items : ");
  scanf("%d",&itemCount);

  for(i=0;i<itemCount;i++)
  {
    printf("\nEnter the dimesion of %d item (W x H)",i+1);
    scanf("%d %d",&item[i].width,&item[i].height);
    item[i].binAllocated=0;
    item[i].x1=0;
    item[i].x2=0;
    item[i].x3=0;
    item[i].x4=0;
    item[i].y1=0;
    item[i].y2=0;
    item[i].y3=0;
    item[i].y4=0;
  }

  for(i=0;i<itemCount;i++)
  {
    if(item[i].width>binWidth || item[i].height>binHeight)
    {
      printf("\n\nItem no %d dimesion is greater then bin dimension,",i+1);
      printf("\nAll items cannot be filled, try again\n");
      return 0;
    }
  }

  binNumber=1;
  binHeightUsed=0;
  binWidthUsed=0;
  maxXUsed=0;
  xUsed=0;
  binHeightRemain=binHeight;
  for(i=0;i<itemCount;i++)
  {
    binWidthRemain=binWidth-binWidthUsed;
    if(item[i].width<=binWidthRemain)
    {
      if(item[i].height<=binHeightRemain)
      {
        item[i].binAllocated=binNumber;
        item[i].x1=binWidthUsed;
        item[i].x3=binWidthUsed;
        item[i].y1=binHeightUsed;
        item[i].y2=binHeightUsed;
        binHeightUsed+=item[i].height;
        xUsed=binWidthUsed+item[i].width;
        item[i].x2=xUsed;
        item[i].x4=xUsed;
        item[i].y3=binHeightUsed;
        item[i].y4=binHeightUsed;
        binHeightRemain=binHeight-binHeightUsed;
        if (maxXUsed<xUsed)
        {
          maxXUsed=xUsed;
        }
        if(binHeightRemain<item[i+1].height)
        {
          binWidthUsed=maxXUsed;
        }
      }
      else
      {//shift to next coloumn, and then add Items
        binWidthUsed=maxXUsed;
        binHeightUsed=0;
        item[i].binAllocated=binNumber;
        item[i].x1=binWidthUsed;
        item[i].x3=binWidthUsed;
        item[i].y1=binHeightUsed;
        item[i].y2=binHeightUsed;
        binHeightUsed+=item[i].height;
        xUsed=binWidthUsed+item[i].width;
        item[i].x2=xUsed;
        item[i].x4=xUsed;
        item[i].y3=binHeightUsed;
        item[i].y4=binHeightUsed;
        binHeightRemain=binHeight-binHeightUsed;
        if (maxXUsed<xUsed)
        {
          maxXUsed=xUsed;
        }
        if(binHeightRemain<item[i+1].height)
        {
          binWidthUsed=maxXUsed;
        }
      }
    }
    else
    {
      //shift to next bin and add to bin
      binNumber++;
      binWidthUsed=0;
      binHeightUsed=0;
      xUsed=0;
      binHeightRemain=binHeight;
      if(item[i].height<=binHeightRemain)
      {
        item[i].binAllocated=binNumber;
        item[i].x1=binWidthUsed;
        item[i].x3=binWidthUsed;
        item[i].y1=binHeightUsed;
        item[i].y2=binHeightUsed;
        binHeightUsed+=item[i].height;
        xUsed=binWidthUsed+item[i].width;
        item[i].x2=xUsed;
        item[i].x4=xUsed;
        item[i].y3=binHeightUsed;
        item[i].y4=binHeightUsed;
        binHeightRemain=binHeight-binHeightUsed;
        if (maxXUsed<xUsed)
        {
          maxXUsed=xUsed;
        }
        if(binHeightRemain<item[i+1].height)
        {
          binWidthUsed=maxXUsed;
        }
      }
    /* else
      {//shift to next coloumn, and then add Items
        binWidthUsed=maxXUsed;
        binHeightUsed=0;
        item[i].binAllocated=binNumber;
        item[i].x1=binWidthUsed;
        item[i].x3=binWidthUsed;
        item[i].y1=binHeightUsed;
        item[i].y2=binHeightUsed;
        binHeightUsed+=item[i].height;
        xUsed=binWidthUsed+item[i].width;
        item[i].x2=xUsed;
        item[i].x4=xUsed;
        item[i].y3=binHeightUsed;
        item[i].y4=binHeightUsed;
        binHeightRemain=binHeight-binHeightUsed;
        if (maxXUsed<xUsed)
        {
          maxXUsed=xUsed;
        }
        if(binHeightRemain<item[i+1].height)
        {
          binWidthUsed=maxXUsed;
        }
      } */
    }
  }
  printf("\n\nItems are now placed in big of size %d X %d",binWidth,binHeight);
  printf("\nItemNo\tBinNo\tWidth\tHeight\t(x1,y1)\t(x2,y2)\t(x3,y3)\t(x4,y4)");
  for(i=0;i<itemCount;i++)
  {
    printf("\n%d\t%d\t%d\t%d\t(%d,%d)\t(%d,%d)\t(%d,%d)\t(%d,%d)",i+1,item[i].binAllocated,item[i].width,item[i].height,item[i].x1,item[i].y1,item[i].x2,item[i].y2,item[i].x3,item[i].y3,item[i].x4,item[i].y4);
  }
  printf("\nTotal Bins Used : %d\n",binNumber);
}


//test line added
