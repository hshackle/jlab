#include "Riostream.h"
#include "TGraph.h"

void poisson_5hz(){
  ifstream in;
  in.open(Form("poisson_5hz.txt"));

  Float_t x;

  const Int_t n_points = 100;
  Double_t count[n_points];

  TH1 *freq = new TH1I("Measured Frequency", "Poisson Measured Frequency vs. Theoretical Distribution", 15, 0, 15);
  TF1 *theory = new TF1("theory", "100 * TMath::Poisson(x, [0])", 0, 15);
  TF1 *fixGaus = new TF1("fixGaus", "100 * TMath::Gaus(x, [0], [1],1)", 0, 15);
  theory->SetParameter(0, 4.9);
  theory->SetParName(0, "Mean Rate");
  fixGaus->SetParameter(0, 6);
  fixGaus->SetParameter(1,3);

// Start a for loop iterating over all lines in the file

  for (Int_t num=0; num < n_points; num++){ 
    in >> x;
    count[num] = x;
    freq -> Fill(x);
  }


  Double_t p[15];
  Double_t y[15];
  Double_t error[15];

  for (Int_t num=1; num < 16; num++){
    p[num-1] = freq->GetBinLowEdge(num);
    y[num-1] = freq->GetBinContent(num);
    error[num-1] = freq->GetBinError(num);
    cout << p[num-1] << " " << y[num-1] << " " << error[num-1] << endl;
  };

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
gStyle->SetErrorX(0);
gStyle->SetOptFit(1111);
graph = new TGraphErrors(15, p, y, zeros, error);
graph->Draw("AP");
graph->SetMarkerStyle(21);
graph->SetMarkerColor(4);
graph->GetXaxis()->SetRangeUser(0, 15);
graph->Draw("AP");
//freq->Draw("PE1");
//theory->Draw("SAME");
graph->Fit("theory");
//graph->Fit("fixGaus");
c1->Update();
}


int main(){
  poisson_5hz();
}

