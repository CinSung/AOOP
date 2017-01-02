#pragma once
#include "Supplier.h"
#include <vector>
#include "MYSQL.h"
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
			date = gcnew List<String^>();
			amount = gcnew List<Int32>();
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  name;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		List<String^>^ date;
		List<Int32>^ amount;
		String^ companyname;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(12, 41);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(408, 300);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Plot";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WarehouseChart::button1_Click);
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(132, 331);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(100, 20);
			this->name->TabIndex = 2;
			this->name->Visible = false;
			this->name->TextChanged += gcnew System::EventHandler(this, &WarehouseChart::name_TextChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &WarehouseChart::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &WarehouseChart::backgroundWorker1_RunWorkerCompleted);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(249, 331);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &WarehouseChart::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(11, 331);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &WarehouseChart::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 354);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &WarehouseChart::label1_Click);
			// 
			// WarehouseChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 369);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->name);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"WarehouseChart";
			this->Text = L"WarehouseChart";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void MarshalString ( String ^ s, string& os ) {  
			using namespace Runtime::InteropServices;  
			const char* chars =   
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			os = chars;  
			Marshal::FreeHGlobal(IntPtr((void*)chars));  
		}  
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		companyname = name->Text;
		backgroundWorker1->RunWorkerAsync();
		this->button1->Enabled = false;
				// rename the series name on topif chaneg series 1
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
		for(int i=0;i<date->Count;i++){
			this->chart1->Series["Series1"]->Points->AddXY(date[i],amount[i]);
		}
		this->button1->Enabled = true;
	}
private: System::Void name_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
