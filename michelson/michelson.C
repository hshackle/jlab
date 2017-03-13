#include "Riostream.h"
#include "TGraph.h"
#include "TMath.h"

void michelson(){
  in = new ifstream;
  in->open("data.txt");

  Float_t x;
  char tmp_str[1000];

  TH1F *h1 = new TH1F("Data", "Measured Wavelength; Voltage Difference between One Wavelength [V]; Frequency", 3, 6.8, 7.2);

  while(1){
    in->getline(tmp_str, 256);
    h1->Fill(atof(tmp_str));
    
    if(!in->good()) break;
  }

  Double_t count[3]= {9.0, 15.0, 4.0};
  Double_t value[3] = {6.8, 7, 7.2};
  Double_t xerror[3];
  Double_t yerror[3];

  for(int i=0; i < 3; i++){
    xerror[i] = value[i] * 2.6*2;
    value[i] = value[i]*44.6*2;
    yerror[i] = TMath::Sqrt(count[i]);
    cout << xerror[i] << " " << value[i] << " " << yerror[i] << " " << count[i] << endl;
  };
  in->close();
  c1 = new TCanvas("c1", "Michelson", 1000, 5000);

  graph = new TGraphErrors(3, value, count, xerror, yerror);
  graph->Draw("AP");

}

int main(){
  michelson();
}
    



