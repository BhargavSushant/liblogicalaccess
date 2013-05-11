/**
 * \file MifareCherryCommands.h
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief Mifare Cherry commands.
 */

#ifndef LOGICALACCESS_MIFARECHERRYCOMMANDS_H
#define LOGICALACCESS_MIFARECHERRYCOMMANDS_H

#include "MifarePCSCCommands.h"
#include "../ReaderCardAdapters/PCSCReaderCardAdapter.h"

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;


namespace logicalaccess
{
	/**
	 * \brief The Mifare commands class for Cherry reader.
	 */
	class LIBLOGICALACCESS_API MifareCherryCommands : public MifarePCSCCommands
	{
		public:			

			/**
			 * \brief Constructor.
			 */
			MifareCherryCommands();

			/**
			 * \brief Destructor.
			 */
			virtual ~MifareCherryCommands();

		
		protected:						
			
			/**
			 * \brief Load a key to the reader.
			 * \param keyno The key number.
			 * \param keytype The mifare key type.
			 * \param key The key byte array.
			 * \param keylen The key byte array length.
			 * \param vol Use volatile memory.
			 * \return true on success, false otherwise.
			 */
			bool loadKey(unsigned char keyno, MifareKeyType keytype, const void* key, size_t keylen, bool vol = false);

			/**
			 * \brief Authenticate a block, given a key number.
			 * \param blockno The block number.
			 * \param keyno The key number, previously loaded with Mifare::loadKey().
			 * \param keytype The key type.
			 * \return true if authenticated, false otherwise.
			 */
			bool authenticate(unsigned char blockno, unsigned char keyno, MifareKeyType keytype);
	};	
}

#endif /* LOGICALACCESS_MIFARECHERRYCOMMANDS_H */

