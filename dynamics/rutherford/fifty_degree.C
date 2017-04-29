#include "Riostream.h"
#include "TGraph.h"

void fifty_degree(){
  list1 = new ifstream;
  list1->open(Form("list"));
  char tmp_str[1000];
  char data_tmp_str[1000];
  double freq;
  int bin = 0;
  TH1F *h1 = new TH1F("Data", "Counts", 2048, 0, 2048);
  while (1){
    list1->getline(tmp_str, 256);
    data = new ifstream;
    data->open(Form(std::to_string(tmp_str)));

    while (1){
      data->getline(data_tmp_str, 256);
      freq = atof(tmp_str);

      h1->Fill(bin, freq);
      bin += 1;
    }

    data->close();
    bin=0;
}
}

int main(){
  fifty_degree();
}


