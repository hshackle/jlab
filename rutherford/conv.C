#include "TF1.h"
#include "Math/WrappedTF1.h"
#include "Math/GaussIntegrator.h"

double conv(double phi){
   TF1 f("Rutherford Function", "1/TMath::Power(sin(x/2), 4)*(1-TMath::Abs(x-phi))/.122 * RooStats::Heaviside(-TMath::Abs(x-phi) + .122)", 0.01, TMath::Pi());
   ROOT::Math::WrappedTF1 wf1(f);
   // Create the Integrator
   ROOT::Math::GaussLegendreIntegrator ig;
   // Set parameters of the integration
   ig.SetFunction(wf1);
   ig.SetRelTolerance(0.001);
   ig.SetNumberPoints(40);
   cout << ig.Integral(0.01, TMath::Pi()) << endl;
   return ig.Integral(0.01, TMath::Pi());
}

int main(){
  conv(2);
}


