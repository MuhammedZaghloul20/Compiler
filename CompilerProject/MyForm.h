#pragma once
#include <string>
#include <iostream>
#include <set>
#include <msclr/marshal_cppstd.h> // Include the C++/CLI string marshal header
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <set>
#include <vector>
#include "validators/Types.h"
#include "validators/Validator.h"
#include "validators/Symbol/ArithmeticOperatorValidator.h"
#include "validators/Symbol/LogicalOperatorValidator.h"
#include "validators/Number/NumberValidator.h"
#include "validators/Identifier/IdentifierValidator.h"
#include "validators/Identifier/KeyWordValidator.h"


using std::endl;
using std::cout;

namespace CompilerProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;



	private:





		std::string main_output(string code) {

			Validator validator = Validator();
			ArithmeticOperatorValidator arithmeticOperatorValidator = ArithmeticOperatorValidator();
			LogicalOperatorValidator logicalOperatorValidator = LogicalOperatorValidator();
			SymbolValidator symbolValidator = SymbolValidator();
			NumberValidator numberValidator = NumberValidator();
			IdentifierValidator identifierValidator = IdentifierValidator();
			KeyWordValidator keyWordValidator = KeyWordValidator();

			symbolValidator.addChild(&arithmeticOperatorValidator);
			symbolValidator.addChild(&logicalOperatorValidator);

			identifierValidator.addChild(&keyWordValidator);

			validator.addChild(&symbolValidator);
			validator.addChild(&identifierValidator);
			validator.addChild(&numberValidator);


			std::vector<std::string> tokens;
			code = "if (x <= 20)\n then c = 15;";

			auto lineTokens = split(code);
			for (const auto& token : lineTokens)
				tokens.emplace_back(token);
			std::string output = "";
			for (const auto& token : tokens) {
				output += token + " " + getNameFromType(validator.validateAndGetType(token)) + '\n';
			}
			return output;
		}

		std::string getNameFromType(Types type) {
			switch (type) {
			case Number:
				return "Number";
			case KeyWord:
				return "Keyword";
			case Identifier:
				return "Identifier";
			case Symbol:
				return "Symbol";
			case ArithmeticOperator:
				return "ArithmeticOperator";
			case LogicalOperator:
				return "LogicalOperator";
			default:
				return "Undefined";
			}
		}

		std::vector<std::string> split(const std::string& line) {
			auto tokens = std::vector<std::string>();
			auto counter = 0;
			std::set<char> delimiters = { ';', '\n', '(', ')', '{', '}', ' ' };
			std::string token;
			while (counter < line.length()) {
				if (delimiters.find(line[counter]) != delimiters.end()) {
					if (!token.empty())
						tokens.emplace_back(token);
					token = "";
				}
				else
					token += line[counter];
				counter++;
			}
			if (!token.empty())
				tokens.emplace_back(token);
			return tokens;
		}

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1400, 549);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::WindowText;
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox2->Location = System::Drawing::Point(12, 575);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(1400, 300);
			this->textBox2->TabIndex = 9;
			this->textBox2->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(1405, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 50);
			this->button1->TabIndex = 10;
			this->button1->Text = L"RUN";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew EventHandler(this, &MyForm::Run);

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1553, 780);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::onChangeParentSize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void onChangeParentSize(System::Object^ sender, System::EventArgs^ e) {


			textBox1->Size = System::Drawing::Size(this->ClientSize.Width * 9 / 10, this->ClientSize.Height * 4 / 6);
			textBox2->Location = System::Drawing::Point(textBox1->Location.X, textBox1->Location.Y + textBox1->Size.Height + 10);
			textBox2->Size = System::Drawing::Size(this->ClientSize.Width * 9 / 10, this->ClientSize.Height / 3 - 50);

		}

	
			

		private: System::Void Run(System::Object^ sender, System::EventArgs^ e) {
			// Get the text from textBox1
			String^ text = textBox1->Text;

			// Convert the System::String^ to std::string
			// Marshal::StringToHGlobalAnsi is used to convert from System::String^ to char*
			// std::string constructor is used to convert from char* to std::string
			std::string code = (const char*)(Marshal::StringToHGlobalAnsi(text)).ToPointer();
			code=main_output(code);
			// Now you can use the inputText variable as a std::string
			// ...
			// 
			// 

			textBox2->Text = gcnew String(code.c_str());

			

		}
			   string compile(string code )
			   {
				   return code;
			   }
		
			


	};
}
