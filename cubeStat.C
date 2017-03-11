#include "Riostream.h"

void cubeStat(){
  cubedata = new ifstream;
  cubedata->open("cubeData.csv");
  double x, xsigma, nothing, nothing2, y, ysigma, z, zsigma, V, Vsigma;
  double xtotal, ytotal, ztotal, Vtotal;
  double xmean, ymean, zmean, Vmean, xstd, ystd, zstd, Vstd;
  char tmp_str[1000];


<<<<<<< HEAD
  TH1F *h1 = new TH1F("Data",";Volume Measured of Aluminum Cuboid (mm^{3});Frequency",16,2700,4300);
=======
  TH1F *h1 = new TH1F("Data",";Volume Measured (mm^{3});Frequency",25,2800,4000);
>>>>>>> e86eb928e69a72599da7b704623003c38ec4a6dc

  while (1){
    
    cubedata->getline(tmp_str, 256, ',');
    nothing = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    nothing2 = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    x = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    xsigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    y = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    ysigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    z = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    zsigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    V = atof(tmp_str);

    cubedata->getline(tmp_str, 256);
    Vsigma = atof(tmp_str);

    if(!cubedata->good()) break;

    h1->Fill(V);
    xtotal += x;
    ytotal += y;
    ztotal += z;
    Vtotal += V;
    xstd += xsigma;
    ystd += ysigma;
    zstd += zsigma;
    Vstd += Vsigma;

  }

  cubedata->close();
  xmean = xtotal/177;
  ymean = ytotal/177;
  zmean = ztotal/177;
  Vmean = Vtotal/177;
  xstd = xstd/177;
  ystd = ystd/177;
  zstd = zstd/177;
  Vstd = Vstd/177;
<<<<<<< HEAD
  h1->SetMarkerStyle(21);
  h1->SetLineWidth(2);
  h1->SetStats(0);
  //gStyle->SetOptFit(1111);
  gStyle->SetErrorX(0);
  h1->Fit("gaus");
  h1->Draw("PE1");

  TH1D *hint = new TH1D("hint", "Fitted gaussian with .95 conf band", 100, 2700, 4300);
  (TVirtualFitter::GetFitter())->GetConfidenceIntervals(hint);
  hint->SetStats(kFALSE);
  hint->SetFillColorAlpha(2, 0.25);
  hint->Draw("e3 same");

  leg = new TLegend(0.1,0.1,0.45,0.3);
  TLegendEntry *data = leg->AddEntry(h1, "Reported Values", "pe");
  leg->AddEntry((TObject*)0, "   #mu = 3407, #sigma = 176", "");
  TLegendEntry *fit = leg->AddEntry(h1->GetFunction("gaus"), "Gaussian Fit (#chi^{2}/ndf = 10.93/9)", "l");
  leg->AddEntry((TObject*)0, "   #mu = 3407 #pm 12, #sigma = 138 #pm 10", "");
  TLegendEntry *band = leg->AddEntry(hint, "95% Confidence Band", "f");
  leg->SetTextSize(0.035);
  leg->SetFillColorAlpha(3,0);
  leg->SetBorderSize(0);
  leg->SetTextAlign(11);
  leg->Draw();
/*
  legData = new TLegend(0.1,0.1,0.45,0.3);
  legData-> SetNColumns(3);
  legData->AddEntry((TObject*)0, "", "");
  legData->AddEntry((TObject*)0, "Data", "");
  legData->AddEntry((TObject*)0, "Fit", "");
  legData->AddEntry((TObject*)0, "Mean", "");
  legData->AddEntry((TObject*)0, "3407.5", "");
  legData->AddEntry((TObject*)0, "3407.1", "");
  legData->AddEntry((TObject*)0, "Std. Dev", "");
  legData->AddEntry((TObject*)0, "175.9", "");
  legData->SetTextSize(0.03);
  legData->SetFillColorAlpha(3,0);
  legData->SetBorderSize(0);
  legData->AddEntry((TObject*)0, "138.4", "");
  legData->Draw();
*/
=======
  h1->SetFillColor(11);
  h1->Draw("SAME");
  h1->Fit("gaus");
  gStyle->SetOptStat();
  gStyle->SetOptFit(1100);
  gStyle->SetLabelFont(132);
  gStyle->SetLegendFont(132);
>>>>>>> e86eb928e69a72599da7b704623003c38ec4a6dc
  cout << xmean << " +- " << xstd << endl;
  cout << ymean << " +- " << ystd <<endl;
  cout << zmean << " +- " << zstd <<  endl;
  cout << Vmean << " +- " << Vstd << endl;
}

int main(){
  cubeStat();
}
    
