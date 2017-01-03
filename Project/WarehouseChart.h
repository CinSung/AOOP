#pragma once
#include "MYSQL.h"
#include "Product.h"
#include "Receipt.h"
#include <vector>
using namespace std;

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for WarehouseChart
	/// </summary>
	public ref class WarehouseChart : public System::Windows::Forms::Form
	{
	public:
		WarehouseChart(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WarehouseChart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected: 
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::TextBox^  textBox1;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		List<String^>^ date;
		List<Int32>^ amount;
		String^ companyname;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  name;
	private: System::Windows::Forms::ComboBox^  selectBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
			 System::ComponentModel::Container ^components;
		public:
		property System::String^ companyName{
			System::String^ get(){
				return name->Text;
			}
			void set(System::String^ text){
				name->Text=text;
			}
		}
		property System::String^ username{
			System::String^ get(){
				return textBox1->Text;
			}
			void set(System::String^ text){
				textBox1->Text=text;
			}
		}
		property System::String^ password{
			System::String^ get(){
				return textBox2->Text;
			}
			void set(System::String^ text){
				textBox2->Text=text;
			}
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->selectBox = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(30, 44);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(447, 300);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(493, 44);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(363, 300);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(377, 350);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(42, 350);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Visible = false;
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(180, 350);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(100, 20);
			this->name->TabIndex = 4;
			this->name->Visible = false;
			// 
			// selectBox
			// 
			this->selectBox->FormattingEnabled = true;
			this->selectBox->Location = System::Drawing::Point(493, 17);
			this->selectBox->Name = L"selectBox";
			this->selectBox->Size = System::Drawing::Size(228, 21);
			this->selectBox->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WarehouseChart::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(755, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &WarehouseChart::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &WarehouseChart::backgroundWorker1_RunWorkerCompleted);
			// 
			// WarehouseChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(926, 372);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->selectBox);
			this->Controls->Add(this->name);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Name = L"WarehouseChart";
			this->Text = L"WarehouseChart";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void fillProduct(){
			array <Int32>^ productID;
			array <String^>^productName;
			array <Double>^ priceForFew;
			string username,password;
			MarshalString ( textBox1->Text, username );
			MarshalString ( textBox2->Text, password );
			MYSQL manager(username,password);
			vector <Product> productList = manager.getProduct();
			productID = gcnew array<Int32> (productList.size());
			productName = gcnew array<String^> (productList.size());
			priceForFew = gcnew array<Double> (productList.size());
			int array_size = productList.size();
			for(int i=0;i<productList.size();i++){
				String^ items = gcnew String(productList[i].getName().c_str());
				productName[i] = items;
				productID[i] = productList[i].getID();
				priceForFew[i] = productList[i].getPriceFew();
				selectBox->Items->Add(items);
			}
		}
		void MarshalString ( String ^ s, string& os ) {  
			using namespace Runtime::InteropServices;  
			const char* chars =   
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			os = chars;  
			Marshal::FreeHGlobal(IntPtr((void*)chars));  
		}  
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		string userName,passWord,productName,supplierName;
		long int ItemID;
		MarshalString ( textBox1->Text, userName );
		MarshalString ( textBox2->Text, passWord );
		MarshalString ( name->Text, supplierName );
		MYSQL manager(userName,passWord );
		vector <Supplier> suppliers = manager.getSupplier();
		vector <Product> products = manager.getProduct();
		for(int i=0;i < suppliers.size();i++){
			if(supplierName == suppliers[i].getCompanyName()){
				ItemID = suppliers[i].getItemID();
				break;
			}
		}
		vector <Receipt> receipts = manager.getReceipt();
		//List<String^>^ date;
		//List<Int32>^ amount;
		for(int i=0;i < receipts.size();i++){
			if(receipts[i].getID() == ItemID){
				String^ buffer = gcnew String(receipts[i].getDate().c_str());
				int index;
				if((index = date->IndexOf(buffer)) == -1){
					date->Add(buffer);
					amount->Add(1);
				}
				else{
					amount[index] += 1;
				}
			}
		}
	}
	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		try			
		{ 
			for(int i=0;i < date->Count;i++){
				this->chart1->Series["Series1"]->Points->AddXY(date[i],amount[i]);
			}
		}catch(Exception ^e)
		{
			 MessageBox::Show(e->Message);
		}
		this->button1->Enabled = true;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			companyname = name->Text;
			backgroundWorker1->RunWorkerAsync();
			this->button1->Enabled = false;
	 }
};
}
