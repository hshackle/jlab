#include "Riostream.h"
#include "TGraph.h"

void mca_raw_100(){
  data = new ifstream;
  data->open(Form("hshackle-4.4kV-112G.Spe"));
  char tmp_str[1000];
  double freq;
  int bin = 0;

  TH1F *h1 = new TH1F("Data", "", 256,0, 600);
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286-.591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetMarkerSize(.75);
  gStyle->SetOptStat(0000);
 h1->Draw("hist");
  h1->GetXaxis()->SetTitle("Energy [kEv]");
  h1->GetYaxis()->SetTitle("Frequency");

  TH1F *h2 = new TH1F("Data", "", 256,0, 600);
  bin = 0;
  data->open(Form("hshackle-5.1kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h2->Fill(bin*0.286286-.591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(21);
  h2->SetMarkerSize(.75);
  gStyle->SetOptStat(0000);
 h2->Draw("SAME");

   TH1F *h3 = new TH1F("Data", "", 256,0, 600);
  bin = 0;
  data->open(Form("hshackle-3.9kV-100G.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h3->Fill(bin*0.286286-.591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  h3->SetMarkerColor(kBlue);
  h3->SetMarkerStyle(21);
  h3->SetMarkerSize(.75);
  gStyle->SetOptStat(0000);
 h3->Draw("SAME");

    TH1F *h4 = new TH1F("Data", "", 256,0, 600);
  bin = 0;
  data->open(Form("hshackle-3.3kV-90G.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h4->Fill(bin*0.286286-.591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  h4->SetMarkerColor(kBlue);
  h4->SetMarkerStyle(21);
  h4->SetMarkerSize(.75);
  gStyle->SetOptStat(0000);
 h4->Draw("SAME");
 
}

int main(){
  mca_raw_100();
}


