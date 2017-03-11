#include "Riostream.h"
#include "TGraph.h"
#include "TMath.h"

void mca(){
  /*
  ifstream in;
  in.open(Form("ASCII-SPE.Spe"));
  */
  in = new ifstream;
  in->open("ASCII-SPE.Spe");
  double nothing;
  char tmp_str[1000];

  Float_t x;

  const Int_t n_points = 2048;
  Double_t count[n_points];

 TH1 *freq = new TH1D("", "Poisson Measured Frequency vs. Theoretical Distribution", 1024, 0, 2048);
// Start a for loop iterating over all lines in the file

  for (Int_t num=0; num < n_points; num++){ 
    in->getline(tmp_str, 256, '     ');
    in->getline(tmp_str, 256);
    x = atof(tmp_str);
    cout << x << endl;
    freq->Fill(num, x);
  }
c1 = new TCanvas("c1", "Poisson Mean Rate", 1000, 5000);
c1 -> SetGrid();
freq->SetMarkerStyle(21);
freq->SetMarkerColor(4);
freq->Draw("P");
c1->Update();
}


int main(){
  mca();
}

