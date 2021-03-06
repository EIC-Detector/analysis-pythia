/**

 *\Brief Macro to extend HERA Physics (G. Wolf) plots (Section 5.2, Fig. 23 & 24) to EIC beam energies
 *\Author: Thomas Krahulik <thomas.krahulik@stonybrook.edu>

 **/

int makePlot_xQ2_HERAvEIC()
{

  /**

   *\HERA Plots use beam energies of Ee = 26.7 GeV and Ep = 820 GeV
   *\EIC Plots use EIC "typical" beam energies of Ee = 10 GeV and Ep = 250 GeV

   **/

  /*----------------------------------*/
  /*-----------Lepton Angle-----------*/
  /*-----------HERA Fig. 23-----------*/
  /*----------------------------------*/

  /*----------Define Angles-----------*/

  TF1 *f_xQ2H_0 = new TF1("f_xQ2H_0" , " 2*[0]*[1]*x*(1 + cos([2])) / (1 + ((x*[1])/(2*[0]))*(1-cos([2])) - 0.5*(1- cos([2])))", 10e-6, 1);
  f_xQ2H_0->SetParameter( 0 , 26.7 );
  f_xQ2H_0->SetParameter( 1 , 820);
  f_xQ2H_0->SetParameter( 2 , (0 * TMath::Pi())/180);
  TF1 *f_xQ2H_30 = (TF1*)f_xQ2H_0->Clone("f_xQ2H_30");  
  f_xQ2H_30->SetParameter( 2 , (30 * TMath::Pi())/180);
  TF1 *f_xQ2H_90 = (TF1*)f_xQ2H_0->Clone("f_xQ2H_90");  
  f_xQ2H_90->SetParameter( 2 , (90 * TMath::Pi())/180);
  TF1 *f_xQ2H_170 = (TF1*)f_xQ2H_0->Clone("f_xQ2H_170");  
  f_xQ2H_170->SetParameter( 2 , (170 * TMath::Pi())/180);

  TF1 *f_xQ2E_0 = new TF1("f_xQ2E_0" , " 2*[0]*[1]*x*(1 + cos([2])) / (1 + ((x*[1])/(2*[0]))*(1-cos([2])) - 0.5*(1- cos([2])))", 10e-6, 1);
  f_xQ2E_0->SetParameter( 0 , 10 );
  f_xQ2E_0->SetParameter( 1 , 250);
  f_xQ2E_0->SetParameter( 2 , (0 * TMath::Pi())/180);
  TF1 *f_xQ2E_30 = (TF1*)f_xQ2E_0->Clone("f_xQ2E_30");  
  f_xQ2E_30->SetParameter( 2 , (30 * TMath::Pi())/180);
  TF1 *f_xQ2E_90 = (TF1*)f_xQ2E_0->Clone("f_xQ2E_90");  
  f_xQ2E_90->SetParameter( 2 , (90 * TMath::Pi())/180);
  TF1 *f_xQ2E_170 = (TF1*)f_xQ2E_0->Clone("f_xQ2E_170");  
  f_xQ2E_170->SetParameter( 2 , (170 * TMath::Pi())/180);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_LepA = new TCanvas();
  c_xQ2_LepA->SetLogx();
  c_xQ2_LepA->SetLogy();

  f_xQ2H_0->Draw();
  f_xQ2H_0->SetLineColor(1);
  f_xQ2H_0->SetLineStyle(1);
  f_xQ2H_0->SetTitle("");
  f_xQ2H_0->GetXaxis()->SetTitle("x");
  f_xQ2H_0->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_0->SetMinimum(1);
  f_xQ2H_0->SetMaximum(10e4);

  f_xQ2H_30->Draw("SAME");
  f_xQ2H_30->SetLineColor(1);
  f_xQ2H_30->SetLineStyle(3);
  f_xQ2H_90->Draw("SAME");
  f_xQ2H_90->SetLineColor(1);
  f_xQ2H_90->SetLineStyle(5);
  f_xQ2H_170->Draw("SAME");
  f_xQ2H_170->SetLineColor(1);
  f_xQ2H_170->SetLineStyle(7);

  f_xQ2E_0->Draw("SAME");
  f_xQ2E_0->SetLineColor(2);
  f_xQ2E_0->SetLineStyle(1);
  f_xQ2E_30->Draw("SAME");
  f_xQ2E_30->SetLineColor(2);
  f_xQ2E_30->SetLineStyle(3);
  f_xQ2E_90->Draw("SAME");
  f_xQ2E_90->SetLineColor(2);
  f_xQ2E_90->SetLineStyle(5);
  f_xQ2E_170->Draw("SAME");
  f_xQ2E_170->SetLineColor(2);
  f_xQ2E_170->SetLineStyle(7);

  TLegend* leg_xQ2_LepA = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_LepA->AddEntry(f_xQ2H_0, "HERA 0^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2H_30, "HERA 30^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2H_90, "HERA 90^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2H_170, "HERA 170^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2E_0, "EIC 0^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2E_30, "EIC 30^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2E_90, "EIC 90^{o}", "L");
  leg_xQ2_LepA->AddEntry(f_xQ2E_170, "EIC 170^{o}", "L");
  leg_xQ2_LepA->Draw();

  /*----------------------------------*/

  /*----------------------------------*/
  /*-----------Lepton Energy----------*/
  /*-----------HERA Fig. 23-----------*/
  /*----------------------------------*/

  /*----------Define Energies---------*/

  TF1 *f_xQ2H_E0 = new TF1("f_xQ2H_E0" , "2*[0]*[2]*( 1 + ((((x*[1]*([2]-[0]))/(x*[1]-[0])) - ([0] - (([0]*([2]-[0]))/(x*[1]-[0])))) / (((x*[1]*([2]-[0]))/(x*[1]-[0])) + ([0] - (([0]*([2]-[0]))/(x*[1]-[0]))))))", 10e-6, 1);
  f_xQ2H_E0->SetParameter( 0 , 26.7 );
  f_xQ2H_E0->SetParameter( 1 , 820.);
  f_xQ2H_E0->SetParameter( 2 , 0. );
  //  TF1 *f_xQ2H_E3 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E3");  
  //  f_xQ2H_E3->SetParameter( 2 , 3);
  TF1 *f_xQ2H_E9 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E9");  
  f_xQ2H_E9->SetParameter( 2 , 9);
  //  TF1 *f_xQ2H_E11 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E11");  
  //  f_xQ2H_E11->SetParameter( 2 , 11);
  TF1 *f_xQ2H_E26_5 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E26_5");  
  f_xQ2H_E26_5->SetParameter( 2 , 26.5);
  //  TF1 *f_xQ2H_E26_9 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E26_9");  
  //  f_xQ2H_E26_9->SetParameter( 2 , 26.9);
  TF1 *f_xQ2H_E30 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E30");  
  f_xQ2H_E30->SetParameter( 2 , 30);
  //  TF1 *f_xQ2H_E100 = (TF1*)f_xQ2H_E0->Clone("f_xQ2H_E100");  
  //  f_xQ2H_E100->SetParameter( 2 , 100);

  TF1 *f_xQ2E_E0 = new TF1("f_xQ2E_E0" , "2*[0]*[2]*( 1 + ((((x*[1]*([2]-[0]))/(x*[1]-[0])) - ([0] - (([0]*([2]-[0]))/(x*[1]-[0])))) / (((x*[1]*([2]-[0]))/(x*[1]-[0])) + ([0] - (([0]*([2]-[0]))/(x*[1]-[0]))))))", 10e-6, 1);
  f_xQ2E_E0->SetParameter( 0 , 10 );
  f_xQ2E_E0->SetParameter( 1 , 250.);
  f_xQ2E_E0->SetParameter( 2 , 0. );
  //  TF1 *f_xQ2E_E3 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E3");  
  //  f_xQ2E_E3->SetParameter( 2 , 3);
  TF1 *f_xQ2E_E9 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E9");  
  f_xQ2E_E9->SetParameter( 2 , 9);
  //  TF1 *f_xQ2E_E11 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E11");  
  //  f_xQ2E_E11->SetParameter( 2 , 11);
  TF1 *f_xQ2E_E26_5 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E26_5");  
  f_xQ2E_E26_5->SetParameter( 2 , 26.5);
  //  TF1 *f_xQ2E_E26_9 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E26_9");  
  //  f_xQ2E_E26_9->SetParameter( 2 , 26.9);
  TF1 *f_xQ2E_E30 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E30");  
  f_xQ2E_E30->SetParameter( 2 , 30);
  //  TF1 *f_xQ2E_E100 = (TF1*)f_xQ2E_E0->Clone("f_xQ2E_E100");  
  //  f_xQ2E_E100->SetParameter( 2 , 100);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_LepE = new TCanvas();
  c_xQ2_LepE->SetLogx();
  c_xQ2_LepE->SetLogy();

  f_xQ2H_E0->Draw();
  f_xQ2H_E0->SetLineColor(1);
  f_xQ2H_E0->SetLineStyle(1);
  f_xQ2H_E0->SetTitle("");
  f_xQ2H_E0->GetXaxis()->SetTitle("x");
  f_xQ2H_E0->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_E0->SetMinimum(1);
  f_xQ2H_E0->SetMaximum(10e4);

  //  f_xQ2H_E3->Draw("SAME");
  //  f_xQ2H_E3->SetLineColor(1);
  //  f_xQ2H_E3->SetLineStyle(3);
  f_xQ2H_E9->Draw("SAME");
  f_xQ2H_E9->SetLineColor(1);
  f_xQ2H_E9->SetLineStyle(5);
  //  f_xQ2H_E11->Draw("SAME");
  // f_xQ2H_E11->SetLineColor(1);
  //  f_xQ2H_E11->SetLineStyle(7);
  f_xQ2H_E26_5->Draw("SAME");
  f_xQ2H_E26_5->SetLineColor(1);
  f_xQ2H_E26_5->SetLineStyle(9);
  //  f_xQ2H_E26_9->Draw("SAME");
  //  f_xQ2H_E26_9->SetLineColor(1);
  //  f_xQ2H_E26_9->SetLineStyle(2);
  f_xQ2H_E30->Draw("SAME");
  f_xQ2H_E30->SetLineColor(1);
  f_xQ2H_E30->SetLineStyle(4);
  //  f_xQ2H_E100->Draw("SAME");
  //  f_xQ2H_E100->SetLineColor(1);
  //  f_xQ2H_E100->SetLineStyle(6);

  f_xQ2E_E0->Draw("SAME");
  f_xQ2E_E0->SetLineColor(2);
  f_xQ2E_E0->SetLineStyle(1);
  //  f_xQ2E_E3->Draw("SAME");
  //  f_xQ2E_E3->SetLineColor(2);
  //  f_xQ2E_E3->SetLineStyle(3);
  f_xQ2E_E9->Draw("SAME");
  f_xQ2E_E9->SetLineColor(2);
  f_xQ2E_E9->SetLineStyle(5);
  // f_xQ2E_E11->Draw("SAME");
  // f_xQ2E_E11->SetLineColor(2);
  // f_xQ2E_E11->SetLineStyle(7);
  f_xQ2E_E26_5->Draw("SAME");
  f_xQ2E_E26_5->SetLineColor(2);
  f_xQ2E_E26_5->SetLineStyle(9);
  // f_xQ2E_E26_9->Draw("SAME");
  // f_xQ2E_E26_9->SetLineColor(2);
  // f_xQ2E_E26_9->SetLineStyle(2);
  f_xQ2E_E30->Draw("SAME");
  f_xQ2E_E30->SetLineColor(2);
  f_xQ2E_E30->SetLineStyle(4);
  // f_xQ2E_E100->Draw("SAME");
  // f_xQ2E_E100->SetLineColor(2);
  // f_xQ2E_E100->SetLineStyle(6);

  TLegend* leg_xQ2_LepE = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_LepE->AddEntry(f_xQ2H_E0, "HERA 0 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2H_E3, "HERA 3 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2H_E9, "HERA 9 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2H_E11, "HERA 11 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2H_E26_5, "HERA 26.5 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2H_E26_9, "HERA 26.9 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2H_E30, "HERA 30 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2H_E100, "HERA 100 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2E_E0, "EIC 0 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2E_E3, "EIC 3 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2E_E9, "EIC 9 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2E_E11, "EIC 11 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2E_E26_5, "EIC 26.5 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2E_E26_9, "EIC 26.9 GeV", "L");
  leg_xQ2_LepE->AddEntry(f_xQ2E_E30, "EIC 30 GeV", "L");
  //  leg_xQ2_LepE->AddEntry(f_xQ2E_E100, "EIC 100 GeV", "L");
  leg_xQ2_LepE->Draw();
 
  /*----------------------------------*/

  /*----------------------------------*/
  /*-------------Jet Angle------------*/
  /*-----------HERA Fig. 23-----------*/
  /*----------------------------------*/

  /*-----------Define Angles----------*/

  TF1 *f_xQ2H_JA180 = new TF1("f_xQ2H_E0" ,"(4 * (x**2)*([1]**2)*[0]*(1-cos([2]))) / (cos([2]) * ([0] -x*[1]) + [0] + x*[1])" , 10e-6, 1);
  f_xQ2H_JA180->SetParameter( 0 , 26.7);
  f_xQ2H_JA180->SetParameter( 1 , 820.);
  f_xQ2H_JA180->SetParameter( 2 , (180 * TMath::Pi())/180 );
  TF1 *f_xQ2H_JA170 = (TF1*)f_xQ2H_JA180->Clone("f_xQ2H_JA170");  
  f_xQ2H_JA170->SetParameter( 2 , (170 * TMath::Pi())/180 );
  TF1 *f_xQ2H_JA90 = (TF1*)f_xQ2H_JA180->Clone("f_xQ2H_JA90");  
  f_xQ2H_JA90->SetParameter( 2 , (90 * TMath::Pi())/180 );
  TF1 *f_xQ2H_JA10 = (TF1*)f_xQ2H_JA180->Clone("f_xQ2H_JA10");  
  f_xQ2H_JA10->SetParameter( 2 , (10 * TMath::Pi())/180);

  TF1 *f_xQ2E_JA180 = new TF1("f_xQ2E_E0" ,"(4 * (x**2)*([1]**2)*[0]*(1-cos([2]))) / (cos([2]) * ([0] -x*[1]) + [0] + x*[1])" , 10e-6, 1);
  f_xQ2E_JA180->SetParameter( 0 , 10);
  f_xQ2E_JA180->SetParameter( 1 , 250.);
  f_xQ2E_JA180->SetParameter( 2 , (180 * TMath::Pi())/180 );
  TF1 *f_xQ2E_JA170 = (TF1*)f_xQ2E_JA180->Clone("f_xQ2E_JA170");  
  f_xQ2E_JA170->SetParameter( 2 , (170 * TMath::Pi())/180 );
  TF1 *f_xQ2E_JA90 = (TF1*)f_xQ2E_JA180->Clone("f_xQ2E_JA90");  
  f_xQ2E_JA90->SetParameter( 2 , (90 * TMath::Pi())/180 );
  TF1 *f_xQ2E_JA10 = (TF1*)f_xQ2E_JA180->Clone("f_xQ2E_JA10");  
  f_xQ2E_JA10->SetParameter( 2 , (10 * TMath::Pi())/180);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_JetA = new TCanvas();
  c_xQ2_JetA->SetLogx();
  c_xQ2_JetA->SetLogy();

  f_xQ2H_JA180->Draw();
  f_xQ2H_JA180->SetLineColor(1);
  f_xQ2H_JA180->SetLineStyle(1);
  f_xQ2H_JA180->SetTitle("");
  f_xQ2H_JA180->GetXaxis()->SetTitle("x");
  f_xQ2H_JA180->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_JA180->SetMinimum(1);
  f_xQ2H_JA180->SetMaximum(10e4);

  f_xQ2H_JA170->Draw("SAME");
  f_xQ2H_JA170->SetLineColor(1);
  f_xQ2H_JA170->SetLineStyle(3);
  f_xQ2H_JA90->Draw("SAME");
  f_xQ2H_JA90->SetLineColor(1);
  f_xQ2H_JA90->SetLineStyle(5);
  f_xQ2H_JA10->Draw("SAME");
  f_xQ2H_JA10->SetLineColor(1);
  f_xQ2H_JA10->SetLineStyle(7);

  f_xQ2E_JA180->Draw("SAME");
  f_xQ2E_JA180->SetLineColor(2);
  f_xQ2E_JA180->SetLineStyle(1);
  f_xQ2E_JA170->Draw("SAME");
  f_xQ2E_JA170->SetLineColor(2);
  f_xQ2E_JA170->SetLineStyle(3);
  f_xQ2E_JA90->Draw("SAME");
  f_xQ2E_JA90->SetLineColor(2);
  f_xQ2E_JA90->SetLineStyle(5);
  f_xQ2E_JA10->Draw("SAME");
  f_xQ2E_JA10->SetLineColor(2);
  f_xQ2E_JA10->SetLineStyle(7);

  TLegend* leg_xQ2_JetA = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_JetA->AddEntry(f_xQ2H_JA180, "HERA 180^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2H_JA170, "HERA 170^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2H_JA90, "HERA 90^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2H_JA10, "HERA 10^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2E_JA180, "EIC 180^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2E_JA170, "EIC 170^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2E_JA90, "EIC 90^{o}", "L");
  leg_xQ2_JetA->AddEntry(f_xQ2E_JA10, "EIC 10^{o}", "L");
  leg_xQ2_JetA->Draw();
 
  /*----------------------------------*/

  /*----------------------------------*/
  /*------------Jet Energy------------*/
  /*-----------HERA Fig. 23-----------*/
  /*----------------------------------*/

  /*----------Define Energies---------*/

  TF1 *f_xQ2H_JE10 = new TF1("f_xQ2H_JE10" , "(4*x*[0]*[1]*([2]-x*[1])) / ([0] - x*[1])", 10e-6, 1);
  f_xQ2H_JE10->SetParameter( 0 , 26.7);
  f_xQ2H_JE10->SetParameter( 1 , 820.);
  f_xQ2H_JE10->SetParameter( 2 , 10 );
  TF1 *f_xQ2H_JE26_7 = (TF1*)f_xQ2H_JE10->Clone("f_xQ2H_JE26_7");  
  f_xQ2H_JE26_7->SetParameter( 2 , 26.7);

  TF1 *f_xQ2E_JE10 = new TF1("f_xQ2E_JE10" , "(4*x*[0]*[1]*([2]-x*[1])) / ([0] - x*[1])", 10e-6, 1);
  f_xQ2E_JE10->SetParameter( 0 , 10);
  f_xQ2E_JE10->SetParameter( 1 , 250);
  f_xQ2E_JE10->SetParameter( 2 , 10 );
  TF1 *f_xQ2E_JE26_7 = (TF1*)f_xQ2E_JE10->Clone("f_xQ2E_JE26_7");  
  f_xQ2E_JE26_7->SetParameter( 2 , 26.7);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_JetE = new TCanvas();
  c_xQ2_JetE->SetLogx();
  c_xQ2_JetE->SetLogy();

  f_xQ2H_JE10->Draw();
  f_xQ2H_JE10->SetLineColor(1);
  f_xQ2H_JE10->SetLineStyle(5);
  f_xQ2H_JE10->SetTitle("");
  f_xQ2H_JE10->GetXaxis()->SetTitle("x");
  f_xQ2H_JE10->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_JE10->SetMinimum(1);
  f_xQ2H_JE10->SetMaximum(10e4);

  f_xQ2H_JE26_7->Draw("SAME");
  f_xQ2H_JE26_7->SetLineColor(1);
  f_xQ2H_JE26_7->SetLineStyle(1);

  f_xQ2E_JE10->Draw("SAME");
  f_xQ2E_JE10->SetLineColor(2);
  f_xQ2E_JE10->SetLineStyle(1);
  f_xQ2E_JE26_7->Draw("SAME");
  f_xQ2E_JE26_7->SetLineColor(2);
  f_xQ2E_JE26_7->SetLineStyle(5);

  TLegend* leg_xQ2_JetE = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_JetE->AddEntry(f_xQ2H_JE10, "HERA 10 GeV", "L");
  leg_xQ2_JetE->AddEntry(f_xQ2H_JE26_7, "HERA 26.7 GeV", "L");
  leg_xQ2_JetE->AddEntry(f_xQ2E_JE10, "EIC 10 GeV", "L");
  leg_xQ2_JetE->AddEntry(f_xQ2E_JE26_7, "EIC 26.7 GeV", "L");
  leg_xQ2_JetE->Draw();
 
  /*----------------------------------*/

  /*----------------------------------*/
  /*-----------Inelasticity-----------*/
  /*-----------HERA Fig. 24-----------*/
  /*----------------------------------*/

  /*-------Define Inelasticities------*/

  TF1 *f_xQ2H_yn0 = new TF1("f_xQ2H_yn0" , "4*x*[0]*[1]*[2]", 10e-7, 1);
  f_xQ2H_yn0->SetParameter( 0 , 26.7);
  f_xQ2H_yn0->SetParameter( 1 , 820.);
  f_xQ2H_yn0->SetParameter( 2 , 1. );
  TF1 *f_xQ2H_yhalf = (TF1*)f_xQ2H_yn0->Clone("f_xQ2H_yhalf");  
  f_xQ2H_yhalf->SetParameter( 2 , 0.5);
  TF1 *f_xQ2H_yn1 = (TF1*)f_xQ2H_yn0->Clone("f_xQ2H_yn1");  
  f_xQ2H_yn1->SetParameter( 2 , 0.1);
  TF1 *f_xQ2H_yn2 = (TF1*)f_xQ2H_yn0->Clone("f_xQ2H_yn2");  
  f_xQ2H_yn2->SetParameter( 2 , 0.01);
  TF1 *f_xQ2H_yn4 = (TF1*)f_xQ2H_yn0->Clone("f_xQ2H_yn4");  
  f_xQ2H_yn4->SetParameter( 2 , 0.0001);

  TF1 *f_xQ2E_yn0 = new TF1("f_xQ2E_yn0" , "4*x*[0]*[1]*[2]", 10e-7, 1);
  f_xQ2E_yn0->SetParameter( 0 , 10);
  f_xQ2E_yn0->SetParameter( 1 , 250.);
  f_xQ2E_yn0->SetParameter( 2 , 1. );
  TF1 *f_xQ2E_yhalf = (TF1*)f_xQ2E_yn0->Clone("f_xQ2E_yhalf");  
  f_xQ2E_yhalf->SetParameter( 2 , 0.5);
  TF1 *f_xQ2E_yn1 = (TF1*)f_xQ2E_yn0->Clone("f_xQ2E_yn1");  
  f_xQ2E_yn1->SetParameter( 2 , 0.1);
  TF1 *f_xQ2E_yn2 = (TF1*)f_xQ2E_yn0->Clone("f_xQ2E_yn2");  
  f_xQ2E_yn2->SetParameter( 2 , 0.01);
  TF1 *f_xQ2E_yn4 = (TF1*)f_xQ2E_yn0->Clone("f_xQ2E_yn4");  
  f_xQ2E_yn4->SetParameter( 2 , 0.0001);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_y = new TCanvas();

  f_xQ2H_yn0->Draw();
  f_xQ2H_yn0->SetLineColor(1);
  f_xQ2H_yn0->SetLineStyle(1);
  f_xQ2H_yn0->SetTitle("");
  f_xQ2H_yn0->GetXaxis()->SetTitle("x");
  f_xQ2H_yn0->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_yn0->SetMinimum(1);
  f_xQ2H_yn0->SetMaximum(10e4);

  f_xQ2H_yhalf->Draw("SAME");
  f_xQ2H_yhalf->SetLineColor(1);
  f_xQ2H_yhalf->SetLineStyle(3);
  f_xQ2H_yn1->Draw("SAME");
  f_xQ2H_yn1->SetLineColor(1);
  f_xQ2H_yn1->SetLineStyle(5);

  f_xQ2E_yn0->Draw("SAME");
  f_xQ2E_yn0->SetLineColor(2);
  f_xQ2E_yn0->SetLineStyle(1);
  f_xQ2E_yhalf->Draw("SAME");
  f_xQ2E_yhalf->SetLineColor(2);
  f_xQ2E_yhalf->SetLineStyle(3);
  f_xQ2E_yn1->Draw("SAME");
  f_xQ2E_yn1->SetLineColor(2);
  f_xQ2E_yn1->SetLineStyle(5);

  TLegend* leg_xQ2_y = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_y->AddEntry(f_xQ2H_yn0, "HERA y = 1", "L");
  leg_xQ2_y->AddEntry(f_xQ2H_yhalf, "HERA y = 0.5", "L");
  leg_xQ2_y->AddEntry(f_xQ2H_yn1, "HERA y = 0.1", "L");
  leg_xQ2_y->AddEntry(f_xQ2E_yn0, "EIC y = 1", "L");
  leg_xQ2_y->AddEntry(f_xQ2E_yhalf, "EIC y = 0.5", "L");
  leg_xQ2_y->AddEntry(f_xQ2E_yn1, "EIC y = 0.1", "L");
  leg_xQ2_y->Draw();

  TCanvas *c_xQ2_ylog = new TCanvas();
  c_xQ2_ylog->SetLogx();
  c_xQ2_ylog->SetLogy();

  f_xQ2H_yn0->Draw();
  f_xQ2H_yn0->SetLineColor(1);
  f_xQ2H_yn0->SetLineStyle(1);
  f_xQ2H_yn0->SetTitle("");
  f_xQ2H_yn0->GetXaxis()->SetTitle("x");
  f_xQ2H_yn0->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_yn0->SetMinimum(10e-2);
  f_xQ2H_yn0->SetMaximum(10e4);

  f_xQ2H_yn2->Draw("SAME");
  f_xQ2H_yn2->SetLineColor(1);
  f_xQ2H_yn2->SetLineStyle(3);
  f_xQ2H_yn4->Draw("SAME");
  f_xQ2H_yn4->SetLineColor(1);
  f_xQ2H_yn4->SetLineStyle(5);

  f_xQ2E_yn0->Draw("SAME");
  f_xQ2E_yn0->SetLineColor(2);
  f_xQ2E_yn0->SetLineStyle(1);
  f_xQ2E_yn2->Draw("SAME");
  f_xQ2E_yn2->SetLineColor(2);
  f_xQ2E_yn2->SetLineStyle(3);
  f_xQ2E_yn4->Draw("SAME");
  f_xQ2E_yn4->SetLineColor(2);
  f_xQ2E_yn4->SetLineStyle(5);

  TLegend* leg_xQ2_ylog = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_ylog->AddEntry(f_xQ2H_yn0, "HERA y = 1", "L");
  leg_xQ2_ylog->AddEntry(f_xQ2H_yn2, "HERA y = 10^{-2}", "L");
  leg_xQ2_ylog->AddEntry(f_xQ2H_yn4, "HERA y = 10^{-4}", "L");
  leg_xQ2_ylog->AddEntry(f_xQ2E_yn0, "EIC y = 1", "L");
  leg_xQ2_ylog->AddEntry(f_xQ2E_yn2, "EIC y = 10^{-2}", "L");
  leg_xQ2_ylog->AddEntry(f_xQ2E_yn4, "EIC y = 10^{-4}", "L");
  leg_xQ2_ylog->Draw();
 
  /*----------------------------------*/

  /*----------------------------------*/
  /*-------Hadronic System Mass-------*/
  /*-----------HERA Fig. 24-----------*/
  /*----------------------------------*/

  /*-----------Define Masses----------*/

  TF1 *f_xQ2H_W10 = new TF1("f_xQ2H_W10" , "([1] - [0]**2) / ((1/x) - 1)", 10e-7, 1);
  f_xQ2H_W10->SetParameter( 0 , 0.938);
  f_xQ2H_W10->SetParameter( 1 , (10)**2 );
  TF1 *f_xQ2H_W50 = (TF1*)f_xQ2H_W10->Clone("f_xQ2H_W50");  
  f_xQ2H_W50->SetParameter( 1 , (50)**2 );
  TF1 *f_xQ2H_W100 = (TF1*)f_xQ2H_W10->Clone("f_xQ2H_W100");  
  f_xQ2H_W100->SetParameter( 1 , (100)**2 );
  TF1 *f_xQ2H_W200 = (TF1*)f_xQ2H_W10->Clone("f_xQ2H_W200");  
  f_xQ2H_W200->SetParameter( 1 , (200)**2);

  TF1 *f_xQ2E_W10 = (TF1*)f_xQ2H_W10->Clone("f_xQ2E_W10");  
  f_xQ2E_W10->SetParameter( 1 , (10)**2 );
  TF1 *f_xQ2E_W50 = (TF1*)f_xQ2H_W10->Clone("f_xQ2E_W50");  
  f_xQ2E_W50->SetParameter( 1 , (50)**2 );
  TF1 *f_xQ2E_W100 = (TF1*)f_xQ2H_W10->Clone("f_xQ2E_W100");  
  f_xQ2E_W100->SetParameter( 1 , (100)**2 );
  TF1 *f_xQ2E_W200 = (TF1*)f_xQ2H_W10->Clone("f_xQ2E_W200");  
  f_xQ2E_W200->SetParameter( 1 , (200)**2);

  /*-----------Plot x-Q2--------------*/

  TCanvas *c_xQ2_W = new TCanvas();

  f_xQ2H_W200->Draw();
  f_xQ2H_W200->SetLineColor(1);
  f_xQ2H_W200->SetLineStyle(1);
  f_xQ2H_W200->SetTitle("");
  f_xQ2H_W200->GetXaxis()->SetTitle("x");
  f_xQ2H_W200->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_W200->SetMinimum(1);
  f_xQ2H_W200->SetMaximum(10e4);

  f_xQ2H_W100->Draw("SAME");
  f_xQ2H_W100->SetLineColor(1);
  f_xQ2H_W100->SetLineStyle(3);
  f_xQ2H_W50->Draw("SAME");
  f_xQ2H_W50->SetLineColor(1);
  f_xQ2H_W50->SetLineStyle(5);
  f_xQ2H_W10->Draw("SAME");
  f_xQ2H_W10->SetLineColor(1);
  f_xQ2H_W10->SetLineStyle(7);

  f_xQ2E_W200->Draw("SAME");
  f_xQ2E_W200->SetLineColor(2);
  f_xQ2E_W200->SetLineStyle(1);
  f_xQ2E_W100->Draw("SAME");
  f_xQ2E_W100->SetLineColor(2);
  f_xQ2E_W100->SetLineStyle(3);
  f_xQ2E_W50->Draw("SAME");
  f_xQ2E_W50->SetLineColor(2);
  f_xQ2E_W50->SetLineStyle(5);
  f_xQ2E_W10->Draw("SAME");
  f_xQ2E_W10->SetLineColor(2);
  f_xQ2E_W10->SetLineStyle(7);

  TLegend* leg_xQ2_W = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_W->AddEntry(f_xQ2H_W10, "HERA W = 10 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2H_W50, "HERA W = 50 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2H_W100, "HERA W = 100 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2H_W200, "HERA W = 200 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2E_W10, "EIC W = 10 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2E_W50, "EIC W = 50 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2E_W100, "EIC W = 100 GeV", "L");
  leg_xQ2_W->AddEntry(f_xQ2E_W200, "EIC W = 200 GeV", "L");
  leg_xQ2_W->Draw();

  TCanvas *c_xQ2_Wlog = new TCanvas();
  c_xQ2_Wlog->SetLogx();
  c_xQ2_Wlog->SetLogy();

  f_xQ2H_W200->Draw();
  f_xQ2H_W200->SetLineColor(1);
  f_xQ2H_W200->SetLineStyle(1);
  f_xQ2H_W200->SetTitle("");
  f_xQ2H_W200->GetXaxis()->SetTitle("x");
  f_xQ2H_W200->GetYaxis()->SetTitle("Q^{2} [GeV]");
  f_xQ2H_W200->SetMinimum(10e-2);
  f_xQ2H_W200->SetMaximum(10e4);

  f_xQ2H_W100->Draw("SAME");
  f_xQ2H_W100->SetLineColor(1);
  f_xQ2H_W100->SetLineStyle(3);
  f_xQ2H_W50->Draw("SAME");
  f_xQ2H_W50->SetLineColor(1);
  f_xQ2H_W50->SetLineStyle(5);
  f_xQ2H_W10->Draw("SAME");
  f_xQ2H_W10->SetLineColor(1);
  f_xQ2H_W10->SetLineStyle(7);

  f_xQ2E_W200->Draw("SAME");
  f_xQ2E_W200->SetLineColor(2);
  f_xQ2E_W200->SetLineStyle(1);
  f_xQ2E_W100->Draw("SAME");
  f_xQ2E_W100->SetLineColor(2);
  f_xQ2E_W100->SetLineStyle(3);
  f_xQ2E_W50->Draw("SAME");
  f_xQ2E_W50->SetLineColor(2);
  f_xQ2E_W50->SetLineStyle(5);
  f_xQ2E_W10->Draw("SAME");
  f_xQ2E_W10->SetLineColor(2);
  f_xQ2E_W10->SetLineStyle(7);

  TLegend* leg_xQ2_Wlog = new TLegend( 0.25, 0.65, 0.45, 0.85);
  leg_xQ2_Wlog->AddEntry(f_xQ2H_W10, "HERA W = 10 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2H_W50, "HERA W = 50 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2H_W100, "HERA W = 100 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2H_W200, "HERA W = 200 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2E_W10, "EIC W = 10 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2E_W50, "EIC W = 50 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2E_W100, "EIC W = 100 GeV", "L");
  leg_xQ2_Wlog->AddEntry(f_xQ2E_W200, "EIC W = 200 GeV", "L");
  leg_xQ2_Wlog->Draw();
 
  /*----------------------------------*/

  /*-----------Make Files-------------*/

   c_xQ2_LepA->Print("Plots/HERA/xQ2_HERAvEIC_LepA.png");
   c_xQ2_LepE->Print("Plots/HERA/xQ2_HERAvEIC_LepE.png");
   c_xQ2_JetA->Print("Plots/HERA/xQ2_HERAvEIC_JetA.png");
   c_xQ2_JetE->Print("Plots/HERA/xQ2_HERAvEIC_JetE.png");
   c_xQ2_y->Print("Plots/HERA/xQ2_HERAvEIC_y.png");
   c_xQ2_ylog->Print("Plots/HERA/xQ2_HERAvEIC_ylog.png");
   c_xQ2_W->Print("Plots/HERA/xQ2_HERAvEIC_W.png");
   c_xQ2_Wlog->Print("Plots/HERA/xQ2_HERAvEIC_Wlog.png");

  return 0;
}
