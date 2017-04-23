#include "Riostream.h"
#include "TGraph.h"

void mca_readout(){
  data = new ifstream;
  data->open(Form("hshackle-1au-50.Spe"));
  char tmp_str[1000];
  int bin_bottom, bin_top;
  bin_bottom = 800;
  bin_top = 1300;
  double count = 0;
  double time = 250000;
  double freq;
  int bin = 0;
  TH1F *h1 = new TH1F("hist", "Counts", 64, 0, 2048);
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
}


int main(){
  mca_readout();
}


