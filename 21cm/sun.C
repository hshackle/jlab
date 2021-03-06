#include "TMath.h"

void sun()
{
  TF1 *fit2 = new TF1("fit2", "[0]*TMath::Power(2*TMath::BesselJ1(3.1415926*TMath::Sin((x-1.553)/360*3.14159)*228.6/21), 2)/(TMath::Power(23.1415926*TMath::Sin((x-1.553)/360*3.14159)*228.6/21, 2))", -40, 40);
  fit2->SetParameter(0, 100);
  fit2->SetParameter(1, 0);
  double y[61] = {103.35, 106.14, 106.28, 106.83, 105.69, 105.15, 108, 106.75, 104.5, 106.7, 105.5, 106.59, 105.99, 106.53, 106.18, 106.55, 107.24, 107.76, 108.91, 109.46, 116.11, 121.99, 129.91, 137.46, 147.87, 162.01, 175.87, 187.64, 199.95, 210.8, 222.71, 209.74, 197.02, 188.94, 175.73, 160.76, 149.29, 138.26, 128.53, 120.16, 115.07, 111.65, 109.48, 107.41, 107.10, 106.97, 106.48, 106.67, 107.00, 106.7, 106.62, 106.44, 105.00, 104.99, 105.72, 105.94, 104.62, 105.76, 104.69, 106.69, 106};
  double yh[61] = {107.88, 107.60, 105.59, 106.58, 106.84, 105.15, 105.85, 107.56, 106.62, 107.35, 106.47, 104.56, 105.87, 105.93, 107.68, 106.67, 107.31, 108.21, 108.62, 108.94, 107.43, 108.11, 108.93, 114.99, 124.31, 140.82, 160.32, 185.07, 207.02, 217.61, 222.71, 222.70, 209.74, 197.02, 188.95, 175.73, 160.76, 149.29, 138.26, 128.53, 120.16, 115.07, 111.65, 109.50, 107.41, 107.10, 106.97, 106.48, 106.67, 107.00, 106.7, 106.62, 106.44, 105.00, 104.99, 105.72, 105.94, 104.63, 105.77, 104.69, 106.69};
  for (int i=0; i < sizeof(y)/sizeof(y[0]); i++)
  {
    y[i] = y[i] - 106;
    yh[i] = yh[i] - 106;
    }
  
  double x[61] = {-30, -29, -28,-27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
  double yerr[61];
  double yherr[61];
  double xerr[61];
  for (int j=0; j < 61; j++){
    yerr[j] = TMath::Sqrt(y[j]);
    yherr[j] = TMath::Sqrt(yh[j]);
    xerr[j] = 0;
 }
 TGraphErrors *azmuth = new TGraphErrors(61, x, y, xerr, yerr);
 TGraphErrors *hor = new TGraphErrors(61, x, yh, xerr, yherr);
 hor->GetYaxis()->SetTitle("Antenna Temperature [K]");
 hor->GetXaxis()->SetTitle("Elevation Angular Offset [#theta]");
 hor->Draw();
 hor->Fit("fit2");
 /*azmuth->GetYaxis()->SetTitle("Antenna Temperature [K]");
 azmuth->GetXaxis()->SetTitle("Azimuth Angular Offset [#theta]");
 azmuth->Draw();
 azmuth->Fit("fit2");*/
 gStyle->SetOptFit(1111);
}
