#include "Riostream.h"

void cubeStat(){
  ifstream in;
  in.open(Form("cubeData.csv"));

  Float_t x;

  TH1F *h1 = new TH1F("Legend","Measured Volume Distribution of Cube",50,2800,4000);

  while (1){
    in >> x;
    if(!in.good()) break;
    h1->Fill(x);
  }

  in.close();
  h1->SetFillColor(11);
  h1->Draw();
  h1->Fit("gaus");
}

int main(){
  cubeStat();
}
    
