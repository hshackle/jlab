#include "Riostream.h"
#include "TGraph.h"

void mca_readout(){
  data = new ifstream;
  data->open(Form("hshackle-1au-15.Spe"));
  char tmp_str[1000];
  int bin_bottom, bin_top;
  bin_bottom = 100;
  bin_top = 1500;
  double count = 0;
  double time = 600;
  double freq;
  int bin = 0;
  TH1F *h1 = new TH1F("hist", "Counts", 2048, 0, 2048);
  while (1){
      data->getline(tmp_str, 256);
      freq = atof(tmp_str);
      h1->Fill(bin, freq);
      if (bin >= bin_bottom && bin <= bin_top){
        count += freq;
      };
      bin += 1;
      if (!data->good()) break;
    }
  data->close();
cout << count << " " << count/time << endl;
h1->Draw();
h1->GetXaxis()->SetTitle("MCA Bin Number");
h1->GetYaxis()->SetTitle("Counts");
gStyle->SetOptFit(1111);
TF1 *f1 = new TF1("f1","32.23*TMath::Landau(-x,-1188.9,43.93)",-2048,2048);
//f1.SetParameters(1,0,0.3, 100); //for example
//h1->Fit("landau");
f1->Draw("SAME");
}


int main(){
  mca_readout();
}


