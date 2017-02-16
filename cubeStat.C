#include "Riostream.h"

void cubeStat(){
  cubedata = new ifstream;
  cubedata->open("cubeData.csv");
  double x, xsigma, nothing, nothing2, y, ysigma, z, zsigma, V, Vsigma;
  double xtotal, ytotal, ztotal, Vtotal;
  double xmean, ymean, zmean, Vmean, xstd, ystd, zstd, Vstd;
  char tmp_str[1000];


  TH1F *h1 = new TH1F("Legend","Measured Volume Distribution of Cube;Volume Measured (mm^3);Frequency",50,2800,4000);

  while (1){
    
    cubedata->getline(tmp_str, 256, ',');
    nothing = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    nothing2 = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    x = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    xsigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    y = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    ysigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    z = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    zsigma = atof(tmp_str);

    cubedata->getline(tmp_str, 256, ',');
    V = atof(tmp_str);

    cubedata->getline(tmp_str, 256);
    Vsigma = atof(tmp_str);

    if(!cubedata->good()) break;

    h1->Fill(V);
    xtotal += x;
    ytotal += y;
    ztotal += z;
    Vtotal += V;
    xstd += xsigma;
    ystd += ysigma;
    zstd += zsigma;
    Vstd += Vsigma;

  }

  cubedata->close();
  xmean = xtotal/177;
  ymean = ytotal/177;
  zmean = ztotal/177;
  Vmean = Vtotal/177;
  xstd = xstd/177;
  ystd = ystd/177;
  zstd = zstd/177;
  Vstd = Vstd/177;
  h1->SetFillColor(11);
  h1->Draw();
  h1->Fit("gaus");
  cout << xmean << " +- " << xstd << endl;
  cout << ymean << " +- " << ystd <<endl;
  cout << zmean << " +- " << zstd <<  endl;
  cout << Vmean << " +- " << Vstd << endl;
}

int main(){
  cubeStat();
}
    
