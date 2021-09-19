/**	@file EncryptedString.h 
	@author: Bernardo Flores
*/

#ifndef ENCRYPTEDSTRING_H
#define ENCRYPTEDSTRING_H
#include <string>
using namespace std;
class EncryptedString
{
	private:
		string encrypt;
	public:
		/** EncryptedString::EncryptedString() : A default constructor made to set the private encrypt variable to an empty string */
		EncryptedString();
		/** EncryptedString::EncryptedString(string str) : is a constructor that calls the Set() method and accepts a string data type to be passed */
		EncryptedString(string str);
		/**	void EntryptedString::Set(string str) : is a method that sets the incoming string into encrypted format by special algorithm */
		void Set(string str);
		/** string EncryptedString::get() const : returns the original string asked to be encrypted while not exposing the encrypted version */
		string get() const;
		/** string EncryptedString::getEncrypted() const : used for debugging purposes, returns the encrypted version of the private data by constant */
		string getEncrypted() const;
};
#endif
