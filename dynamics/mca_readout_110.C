#include "Riostream.h"
#include "TGraph.h"

void mca_readout_110(){
  data = new ifstream;
  data->open(Form("hshackle-5kV-112G.Spe"));
  char tmp_str[1000];
  double freq;
  int bin = 0;

  TH2F *h1 = new TH2F("Data", "Electron Count Rate", 30, 200, 500, 12, 3.9, 5.1);
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 5.0, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  data->open(Form("hshackle-4.9kV-112G.Spe"));
  bin = 0;

  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.9, freq);
    bin += 1;

    if(!data->good()) break;
  }
  data->close();
  data->open(Form("hshackle-4.8kV-112G.Spe"));  
  bin = 0;

  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.8, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  data->open(Form("hshackle-4.7kV-112G.Spe"));
  bin = 0;

  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.7, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();
  data->open(Form("hshackle-4.6kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.65, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();
   data->open(Form("hshackle-4.5kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.5, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();
    data->open(Form("hshackle-4.4kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.4, freq);
    bin += 1;

    if(!data->good()) break;
  }
  data->close();

    data->open(Form("hshackle-4.3kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.3, freq);
    bin += 1;

    if(!data->good()) break;
  }

 data->close();
 data->open(Form("hshackle-4.2kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.2, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();
    data->open(Form("hshackle-4.1kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.15, freq);
    cout << freq << endl;
    bin += 1;

    if(!data->good()) break;
  }
  data->close();

    data->open(Form("hshackle-4.0kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 4.0, freq);
    bin += 1;

    if(!data->good()) break;
  }

 data->close();
     data->open(Form("hshackle-3.9kV-112G.Spe"));
  bin = 0;


  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, 3.9, freq);
    bin += 1;

    if(!data->good()) break;
  }

 data->close();
 h1->Draw("LEGO2");
  h1->GetXaxis()->SetTitle("Energy [kEv]");
  h1->GetYaxis()->SetTitle("Voltage [kV]");
 h1->Draw("LEGO2");
}

int main(){
  mca_readout_110();
}


