#include "Riostream.h"
#include "TGraph.h"
#include "TMath.h"

void michelson(){
  Float_t x;
  char tmp_str[1000];

  TH1F *h1 = new TH1F("Data", "Measured Voltage; Voltage Difference between One Wavelength [V]; Frequency", 3, 6.8, 7.4);
  Double_t count[3]= {9.0, 15.0, 4.0};
  Double_t value[3] = {6.8, 7, 7.2};
  Double_t xerror[3];
  Double_t yerror[3];

  for(int i=0; i < 3; i++){
    xerror[i] = 0.14;
    yerror[i] = TMath::Sqrt(count[i]);
    cout << xerror[i] << " " << value[i] << " " << yerror[i] << " " << count[i] << endl;
  };
  c1 = new TCanvas("c1", "Michelson", 1000, 5000);

  graph = new TGraphErrors(3, value, count, xerror, yerror);
  graph->SetMarkerStyle(21);
  graph->SetTitle("");
  graph->GetXaxis()->SetTitle("Measured Voltage Difference");
  graph->GetYaxis()->SetTitle("Frequency");
  graph->Draw("AP");
  graph->GetXaxis()->SetLimits(6.6, 7.4);
  graph->Draw("AP");
  c1->Update();



}

int main(){
  michelson();
}
    



