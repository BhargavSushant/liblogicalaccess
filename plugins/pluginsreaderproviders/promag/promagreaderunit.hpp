/**
 * \file promagreaderunit.hpp
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief Promag Reader unit.
 */

#ifndef LOGICALACCESS_PROMAGREADERUNIT_HPP
#define LOGICALACCESS_PROMAGREADERUNIT_HPP

#include "logicalaccess/readerproviders/readerunit.hpp"
#include "promagreaderunitconfiguration.hpp"

namespace logicalaccess
{
    class Profile;
    class PromagReaderCardAdapter;
    class PromagReaderProvider;

    /**
     * \brief The Promag reader unit class.
     */
    class LIBLOGICALACCESS_API PromagReaderUnit : public ReaderUnit
    {
    public:

        /**
         * \brief Constructor.
         */
        PromagReaderUnit();

        /**
         * \brief Destructor.
         */
        virtual ~PromagReaderUnit();

        /**
         * \brief Get the reader unit name.
         * \return The reader unit name.
         */
        virtual std::string getName() const;

        /**
         * \brief Get the connected reader unit name.
         * \return The connected reader unit name.
         */
        virtual std::string getConnectedName();

        /**
         * \brief Set the card type.
         * \param cardType The card type.
         */
        virtual void setCardType(std::string cardType);

        /**
         * \brief Wait for a card insertion.
         * \param maxwait The maximum time to wait for, in milliseconds. If maxwait is zero, then the call never times out.
         * \return True if a card was inserted, false otherwise. If a card was inserted, the name of the reader on which the insertion was detected is accessible with getReader().
         * \warning If the card is already connected, then the method always fail.
         */
        virtual bool waitInsertion(unsigned int maxwait);

        /**
         * \brief Wait for a card removal.
         * \param maxwait The maximum time to wait for, in milliseconds. If maxwait is zero, then the call never times out.
         * \return True if a card was removed, false otherwise. If a card was removed, the name of the reader on which the removal was detected is accessible with getReader().
         */
        virtual bool waitRemoval(unsigned int maxwait);

        /**
         * \brief Create the chip object from card type.
         * \param type The card type.
         * \return The chip.
         */
        virtual std::shared_ptr<Chip> createChip(std::string type);

        /**
         * \brief Get the first and/or most accurate chip found.
         * \return The single chip.
         */
        virtual std::shared_ptr<Chip> getSingleChip();

        /**
         * \brief Get chip available in the RFID rang.
         * \return The chip list.
         */
        virtual std::vector<std::shared_ptr<Chip> > getChipList();

        /**
         * \brief Get the current chip in air.
         * \return The chip in air.
         */
        std::shared_ptr<Chip> getChipInAir();

        /**
         * \brief Get the default Promag reader/card adapter.
         * \return The default Promag reader/card adapter.
         */
        virtual std::shared_ptr<PromagReaderCardAdapter> getDefaultPromagReaderCardAdapter();

        /**
         * \brief Connect to the card.
         * \return True if the card was connected without error, false otherwise.
         *
         * If the card handle was already connected, connect() first call disconnect(). If you intend to do a reconnection, call reconnect() instead.
         */
        bool connect();

        /**
         * \brief Disconnect from the reader.
         * \see connect
         *
         * Calling this method on a disconnected reader has no effect.
         */
        void disconnect();

        /**
         * \brief Check if the card is connected.
         * \return True if the card is connected, false otherwise.
         */
        virtual bool isConnected();

        /**
         * \brief Connect to the reader. Implicit connection on first command sent.
         * \return True if the connection successed.
         */
        virtual bool connectToReader();

        /**
         * \brief Disconnect from reader.
         */
        virtual void disconnectFromReader();

        /**
         * \brief Get the reader ping command.
         * \return The ping command.
         */
        virtual std::vector<unsigned char> getPingCommand() const;

        /**
         * \brief Get a string hexadecimal representation of the reader serial number
         * \return The reader serial number or an empty string on error.
         */
        virtual std::string getReaderSerialNumber();

        /**
         * \brief Serialize the current object to XML.
         * \param parentNode The parent node.
         */
        virtual void serialize(boost::property_tree::ptree& parentNode);

        /**
         * \brief UnSerialize a XML node to the current object.
         * \param node The XML node.
         */
        virtual void unSerialize(boost::property_tree::ptree& node);

        /**
         * \brief Retrieve reader identifier.
         * \return True on success, false otherwise. False means it's not a TMC reader connected to COM port or COM port inaccessible.
         */
        bool retrieveReaderIdentifier();

        /**
         * \brief Get the Promag reader identifier.
         * \return The Promag reader identifier.
         */
        std::vector<unsigned char> getPromagIdentifier();

        /**
         * \brief Get the Promag reader unit configuration.
         * \return The Promag reader unit configuration.
         */
        std::shared_ptr<PromagReaderUnitConfiguration> getPromagConfiguration() { return std::dynamic_pointer_cast<PromagReaderUnitConfiguration>(getConfiguration()); };

        /**
         * \brief Get the Promag reader provider.
         * \return The Promag reader provider.
         */
        std::shared_ptr<PromagReaderProvider> getPromagReaderProvider() const;

    protected:

        /**
         * \brief The Promag reader identifier.
         */
        std::vector<unsigned char> d_promagIdentifier;
    };
}

#endif