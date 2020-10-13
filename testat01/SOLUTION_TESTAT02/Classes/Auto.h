#include <string>

// Comment to use explicit constructor.
#define useConversionConstructor

#ifdef useConversionConstructor
    #define CHAR_CONVERSION_CONST
#else 
    #define CHAR_EXPLICIT_CONST
#endif

class Auto {
	// 'const' data need to be initialized
	// in initialization_list!
	const unsigned int constructionYear;
	unsigned int thisCarsPS;
	std::string brand;

public:
	static unsigned int carCounter;
	char* model;

	// ----------------------------------------------------------
	// CONSTRUCTORS
	// ----------------------------------------------------------
	Auto();

	// Explicit and conversion constructors.
    #ifdef CHAR_CONVERSION_CONST
	Auto(const char*);
    #endif

    #ifdef CHAR_EXPLICIT_CONST
	explicit Auto(const char*);
    #endif

	Auto(std::string brand, const char* model);

	// Copy constructor declaration.
	Auto(const Auto&);
	// ----------------------------------------------------------


	// ----------------------------------------------------------
	// DESTRUCTOR
	// ----------------------------------------------------------
	~Auto();
	// ----------------------------------------------------------


	// ----------------------------------------------------------
	// OBJECT FUNCTIONS
	// ----------------------------------------------------------
	Auto& operator=(const Auto& s);
	void swap(Auto* a);
	// ----------------------------------------------------------


	// Member functions
	unsigned int getNumberOfCars();
	void showAddressOfThisCar();

	void setCarType(std::string brand);
	void setPS(unsigned int ps);

	const std::string getCarType() const;
	unsigned int getPS() const;
};