/**

 *\Brief Macro to reproduce EIC LoI Feb. 2014 (arXiv:1402.1209v1) Fig. 2.4, 2.8, & 2.9
 *\Author: Thomas Krahulik <thomas.krahulik@stonybrook.edu> 

 **/


int makePlot_LoI_xQ2(
		     const TString infile = // /path/to/input/file ,
		     )

{
  tkStyle->SetOptStat(kFALSE);

  /*--------------Get Input File--------------*/

  TFile *f_pyth = new TFile( infile, "OPEN");
  TTree* T_pyth = (TTree*)f_pyth->Get("T");
  T_pyth->Print();

  /*------------------------------------------*/
  /*---------------Define Cuts----------------*/

  TCut electron_cut = "particles.fPdgCode == 11";
  TCut hadron_cut = "abs(particles.fPdgCode) > 100";
  TCut kaon_cut = "abs(particles.fPdgCode) == 321 || particles.fPdgCode == 311";
  TCut No_DIRC =  "TMath::ASinH(particles.fPz/sqrt(particles.fPx**2 + particles.fPy**2)) > 1";

  /*------------------------------------------*/
  /*---------x-Q2 Space for Electrons---------*/
  /*------------------------------------------*/

  /*------------------------------------------*/
  /*------------Create Histograms-------------*/
  /*------------------------------------------*/
  /*---------------Histogram 1----------------*/

  TH2F* hQ2x_e_1 = new TH2F("hQ2x_e_1", "", 40, -4, 0, 60, 0, 3);
  TAxis *xaxis_1 = hQ2x_e_1->GetXaxis();
  TAxis *yaxis_1 = hQ2x_e_1->GetYaxis();
  int xbins_1 = xaxis_1->GetNbins();
  int ybins_1 = yaxis_1->GetNbins();

  Axis_t xmin_1 = xaxis_1->GetXmin();
  Axis_t xmax_1 = xaxis_1->GetXmax();
  Axis_t xwidth_1 = (xmax_1 - xmin_1 ) / xbins_1;
  Axis_t *new_xbins_1 = new Axis_t[xbins_1 + 1];

   for( int i =0; i <= xbins_1; i++)
     {
       new_xbins_1[i] = TMath::Power( 10, xmin_1 + i*xwidth_1);
     }
   xaxis_1->Set(xbins_1, new_xbins_1);
   
   Axis_t ymin_1 = yaxis_1->GetXmin();
   Axis_t ymax_1 = yaxis_1->GetXmax();
   Axis_t ywidth_1 = (ymax_1 - ymin_1) / ybins_1;
   Axis_t *new_ybins_1 = new Axis_t[ybins_1 + 1];
   
   for( int i2 =0; i2 <= ybins_1; i2++)
     {
       new_ybins_1[i2] = TMath::Power( 10, ymin_1 + i2*ywidth_1);
     }
   
   yaxis_1->Set(ybins_1, new_ybins_1);

  /*---------------Histogram 2 ---------------*/
   TH2F* hQ2x_e_2 = new TH2F("hQ2x_e_2", "", 40, -4, 0, 60, 0, 3);

   TAxis *xaxis_2 = hQ2x_e_2->GetXaxis();
   int xbins_2 = xaxis_2->GetNbins();
   Axis_t xmin_2 = xaxis_2->GetXmin();
   Axis_t xmax_2 = xaxis_2->GetXmax();
   Axis_t xwidth_2 = (xmax_2 - xmin_2 ) / xbins_2;
   Axis_t *new_xbins_2 = new Axis_t[xbins_2 + 1];

   for( int i =0; i <= xbins_2; i++)
     {
       new_xbins_2[i] = TMath::Power( 10, xmin_2 + i*xwidth_2);
     }
   xaxis_2->Set(xbins_2, new_xbins_2);

   TAxis *yaxis_2 = hQ2x_e_2->GetYaxis();   
   int ybins_2 = yaxis_2->GetNbins();
   Axis_t ymin_2 = yaxis_2->GetXmin();
   Axis_t ymax_2 = yaxis_2->GetXmax();
   Axis_t ywidth_2 = (ymax_2 - ymin_2) / ybins_2;
   Axis_t *new_ybins_2 = new Axis_t[ybins_2 + 1];
   
   for( int i2 =0; i2 <= ybins_1; i2++)
     {
       new_ybins_2[i2] = TMath::Power( 10, ymin_2 + i2*ywidth_2);
       //       std:: cout << "New Bins:" << new_ybins_2[i2] << endl;
     }
   
   yaxis_2->Set(ybins_2, new_ybins_2);
  /*------------------------------------------*/
  /*-------------Plot x-Q2 Space--------------*/
  /*------------------------------------------*/
   TCanvas *cQ2x_e = new TCanvas("cQ2x_e");
   cQ2x_e->SetLogx();
   cQ2x_e->SetLogy();
   T_pyth->Draw("Q2:x>>hQ2x_e_1", electron_cut && "x < 1 && y > 0.01 && y < 0.95" , "colz");

   TCanvas *cQ2x_e_2 = new TCanvas("cQ2x_e_2");
   cQ2x_e_2->SetLogx();
   cQ2x_e_2->SetLogy();
   T_pyth->Draw("Q2:x>>hQ2x_e_2", electron_cut && "x < 1 && y > 0.01 && y < 0.95 && particles.fE > 2" , "colz");
   hQ2x_e_2->Divide(hQ2x_e_1);

   hQ2x_e_1->GetXaxis()->SetTitle("x");
   hQ2x_e_1->GetYaxis()->SetTitle("Q^{2} [GeV^{2}]");

   /*-------------Plot y Lines----------------*/
   TF1 *f_y1 = new TF1("f_y1", "4*x*[0]*[1]*[2]", 10e-5, 1);
   f_y1->SetParameter( 0, 10);
   f_y1->SetParameter( 1, 250);
   f_y1->SetParameter( 2, 1);
   TF1 *f_y001 = (TF1*)f_y1->Clone("f_y01");
   f_y001->SetParameter(2 , 0.01);

   f_y1->Draw("SAME");
   f_y1->SetLineColor(1);
   f_y001->Draw("SAME");
   f_y001->SetLineColor(1);

   //   cQ2x_e->Print("Plots/Pythia_Q2x_e_10M_250x010.eps");
   //   cQ2x_e->Print("Plots/Pythia_Q2x_e_10M_250x010.png");

  /*------------------------------------------*/
  /*-----------x-Q2 Space for Kaons-----------*/
  /*------------------------------------------*/

  /*------------------------------------------*/
  /*------------Create Histogram--------------*/
  /*------------------------------------------*/
  /*---------------Histogram 1----------------*/
 
   TH2F* hQ2x_K = new TH2F("hQ2x_K", "", 40, -4, 0, 60, 0, 4);
   TAxis *xaxis_K = hQ2x_K->GetXaxis();
   int xbins_K = xaxis_K->GetNbins();
   Axis_t xmin_K = xaxis_K->GetXmin();
   Axis_t xmax_K = xaxis_K->GetXmax();
   Axis_t xwidth_K = (xmax_K - xmin_K ) / xbins_K;
   Axis_t *new_xbins_K = new Axis_t[xbins_K + 1];

   for( int i =0; i <= xbins_K; i++)
     {
       new_xbins_K[i] = TMath::Power( 10, xmin_K + i*xwidth_K);
     }
   xaxis_K->Set(xbins_K, new_xbins_K);
   
   TAxis *yaxis_K = hQ2x_K->GetYaxis();
   int ybins_K = yaxis_K->GetNbins();
   Axis_t ymin_K = yaxis_K->GetXmin();
   Axis_t ymax_K = yaxis_K->GetXmax();
   Axis_t ywidth_K = (ymax_K - ymin_K) / ybins_K;
   Axis_t *new_ybins_K = new Axis_t[ybins_K + 1];
   
   for( int i2 =0; i2 <= ybins_K; i2++)
     {
       new_ybins_K[i2] = TMath::Power( 10, ymin_K + i2*ywidth_K);
       //      std:: cout << "New Bins:" << new_ybins_K[i2] << endl;
     }
   
   yaxis_K->Set(ybins_K, new_ybins_K);
  /*------------------------------------------*/
  /*-------------Plot x-Q2 Space--------------*/
  /*------------------------------------------*/
  TCanvas *cQ2x_K = new TCanvas("cQ2x_K");  
  cQ2x_K->SetLogx();
  cQ2x_K->SetLogy();
  cQ2x_K->SetLogz();

  T_pyth->Draw("Q2:x>>hQ2x_K", kaon_cut && "W2 > 10 & y > 0.01 && y < 0.95" , "colz");
  //  T_pyth->Draw("Q2:x>>hQ2x_K", "abs(particles.fPdgCode) == 321" , "colz");
  hQ2x_K->GetXaxis()->SetTitle("x");
  hQ2x_K->GetYaxis()->SetTitle("Q^{2} [GeV^{2}]");

  //  cQ2x_K->Print("Plots/LoI_250x010/Pythia_Q2x_K_10M_250x010.eps");
  //  cQ2x_K->Print("Plots/LoI_250x010/Pythia_Q2x_K_10M_250x010.png");

  /*------------------------------------------*/
  /*-----------x-Q2 Space for Kaons-----------*/
  /*------Excluding Certain PID Detectors-----*/
  /*------------------------------------------*/

  /*------------------------------------------*/
  /*------------Create Histograms-------------*/
  /*------------------------------------------*/
  /*---------------Histogram 1----------------*/
  TH2F* hQ2x_K_NoDIRC = new TH2F("hQ2x_K_NoDIRC", "", 40, -4, 0, 60, 0, 4);

  TAxis *xaxis_K_NoDIRC = hQ2x_K_NoDIRC->GetXaxis();
  int xbins_K_NoDIRC = xaxis_K_NoDIRC->GetNbins();
  Axis_t xmin_K_NoDIRC = xaxis_K_NoDIRC->GetXmin();
  Axis_t xmax_K_NoDIRC = xaxis_K_NoDIRC->GetXmax();
  Axis_t xwidth_K_NoDIRC = (xmax_K_NoDIRC - xmin_K_NoDIRC ) / xbins_K_NoDIRC;
  Axis_t *new_xbins_K_NoDIRC = new Axis_t[xbins_K_NoDIRC + 1];

  for( int i =0; i <= xbins_K_NoDIRC; i++)
    {
      new_xbins_K_NoDIRC[i] = TMath::Power( 10, xmin_K_NoDIRC + i*xwidth_K_NoDIRC);
    }
  xaxis_K_NoDIRC->Set(xbins_K_NoDIRC, new_xbins_K_NoDIRC);
   
  TAxis *yaxis_K_NoDIRC = hQ2x_K_NoDIRC->GetYaxis();
  int ybins_K_NoDIRC = yaxis_K_NoDIRC->GetNbins();
  Axis_t ymin_K_NoDIRC = yaxis_K_NoDIRC->GetXmin();
  Axis_t ymax_K_NoDIRC = yaxis_K_NoDIRC->GetXmax();
  Axis_t ywidth_K_NoDIRC = (ymax_K_NoDIRC - ymin_K_NoDIRC) / ybins_K_NoDIRC;
  Axis_t *new_ybins_K_NoDIRC = new Axis_t[ybins_K_NoDIRC + 1];
   
  for( int i2 =0; i2 <= ybins_K_NoDIRC; i2++)
    {
      new_ybins_K_NoDIRC[i2] = TMath::Power( 10, ymin_K_NoDIRC + i2*ywidth_K_NoDIRC);
      //      std:: cout << "New Bins:" << new_ybins_1[i2] << endl;
    }
   
  yaxis_K_NoDIRC->Set(ybins_K_NoDIRC, new_ybins_K_NoDIRC);
  /*------------------------------------------*/
  /*-------------Plot x-Q2 Space--------------*/
  /*------------------------------------------*/
  TCanvas *cQ2x_K_NoDIRC = new TCanvas("cQ2x_K_NoDIRC");
  cQ2x_K_NoDIRC->SetLogx();
  cQ2x_K_NoDIRC->SetLogy();

  T_pyth->Draw("Q2:x>>hQ2x_K_NoDIRC", kaon_cut && No_DIRC && "y > 0.01 && y < 0.95 && W2 > 10" , "colz"); //Eta > 1: Excludes DIRC
  //R > 300cm or Eta < 1: Excludes RICH
  //R < 300 cm or Eta < 1: Excludes Aerogel

  hQ2x_K_NoDIRC->Divide(hQ2x_K);

  hQ2x_K_NoDIRC->GetXaxis()->SetTitle("x");
  hQ2x_K_NoDIRC->GetYaxis()->SetTitle("Q^{2} [GeV^{2}]");

  //  cQ2x_K_NoDIRC->Print("Plots/LoI_250x010/Pythia_Q2x_K_NoDIRC_10M_250x010.eps");
  //  cQ2x_K_NoDIRC->Print("Plots/LoI_250x010/Pythia_Q2x_K_NoDIRC_10M_250x010.png");

  return 0;

}
