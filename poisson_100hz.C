#include "Riostream.h"
#include "TGraph.h"
#include "TMath.h"

void poisson_100hz(){
  ifstream in;
  in.open(Form("poisson_100hz.txt"));

  Float_t x;

  const Int_t n_points = 100;
  Double_t count[n_points];

 TH1 *freq = new TH1D("Data", "Poisson Measured Frequency vs. Theoretical Distribution", 70, 70, 140);
 //TF1 *theory = new TF1("theory", "103.8^x * TMath::Exp(-103.8)/TMath::Gamma(x)", 80, 140);
 TF1 *theory = new TF1("theory", "100 * TMath::Gaus(x, 8)", 70, 140);
// Start a for loop iterating over all lines in the file

  for (Int_t num=0; num < n_points; num++){ 
    in >> x;
    count[num] = x;
    cout << x << endl;
    freq->Fill(x);
  }

Double_t avg[n_points];
avg[0] = count[0];

  for (Int_t num=1; num < n_points; num++){
    avg[num] = avg[num-1] + count[num];
  }

for (Int_t num=0; num < n_points; num++){
  avg[num] = avg[num]/(num+1);
}

Double_t err[n_points];
for (Int_t num=0; num < n_points; num++){
  err[num] = 1/sqrt(num+1);
}
c1 = new TCanvas("c1", "Poisson Mean Rate", 1000, 5000);
c1 -> SetGrid();

Double_t xval[n_points];
for (Int_t num=0; num < n_points; num++){
  xval[num] = num + 1;
}
Double_t zeros[n_points];
/*
gr = new TGraphErrors(100, xval, avg, zeros, err);
gr->SetTitle("Mean Rate of Gamma Ray Detections");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);
gr->GetXaxis()->SetTitle("Time [s]");
gr->GetYaxis()->SetTitle("Average detections per second");
gr->Draw("ALP");
*/
freq->SetMarkerStyle(21);
freq->SetMarkerColor(4);
gStyle->SetErrorX(0);
freq->Draw("PE1");
theory->Draw("SAME");
c1->Update();
}


int main(){
  poisson_100hz();
}

