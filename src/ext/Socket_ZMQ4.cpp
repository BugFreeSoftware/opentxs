/************************************************************
 *
 *  zmq4.cpp
 *  OTSocket with zmq4
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <opentxs/core/stdafx.hpp>
#include <opentxs/ext/Socket_ZMQ4.hpp>
#include <opentxs/core/OTLog.hpp>

#include <cppzmq/zmq.hpp>

#include <string>

namespace opentxs
{

class OTSocket_ZMQ_4::ZMQ4
{
public:
    ZMQ4();
    ~ZMQ4();

    zmq::context_t* context_zmq;
    zmq::socket_t* socket_zmq;
};

OTSocket_ZMQ_4::ZMQ4::ZMQ4()
    : context_zmq(nullptr)
    , socket_zmq(nullptr)
{
}

OTSocket_ZMQ_4::ZMQ4::~ZMQ4()
{
    delete socket_zmq;
    delete context_zmq;
}

OTSocket_ZMQ_4::OTSocket_ZMQ_4()
    : m_pzmq(new ZMQ4())
{
}

OTSocket_ZMQ_4::~OTSocket_ZMQ_4()
{
    CloseSocket();
    delete (m_pzmq);
}

bool OTSocket_ZMQ_4::CloseSocket(const bool bNewContext /*= false*/)
{
    if (!m_bInitialized) return false;
    if (!m_HasContext && !bNewContext) return false;

    if (nullptr != m_pzmq->socket_zmq) zmq_close(m_pzmq->socket_zmq);
    if (nullptr != m_pzmq->socket_zmq) delete m_pzmq->socket_zmq;
    m_pzmq->socket_zmq = nullptr;

    m_bConnected = false;
    m_bListening = false;

    return true;
}

bool OTSocket_ZMQ_4::NewSocket(const bool bIsRequest)
{
    if (!m_bInitialized) return false;
    if (!m_HasContext) return false;

    if (!CloseSocket()) return false;

    try {
        m_pzmq->socket_zmq = new zmq::socket_t(
            *m_pzmq->context_zmq,
            bIsRequest ? ZMQ_REQ : ZMQ_REP); // make a new socket
    }
    catch (std::exception& e) {
        OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__, e.what());
        OT_FAIL;
    }

    if (nullptr == m_pzmq->socket_zmq) {
        OTLog::vError("%s: Error: %s failed to be created!\n", __FUNCTION__,
                      "m_pzmq->socket_zmq");
        OT_FAIL;
    }

    const int linger = 0; // close immediately

    try {
        m_pzmq->socket_zmq->setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
    }
    catch (std::exception& e) {
        OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__, e.what());
        OT_FAIL;
    }

    m_bConnected = false;
    m_bListening = false;

    return true;
}

bool OTSocket_ZMQ_4::NewContext()
{
    if (!m_bInitialized) return false;

    m_HasContext = false;

    if (!CloseSocket(true)) return false;

    if (nullptr != m_pzmq->context_zmq) zmq_term(m_pzmq->context_zmq);
    if (nullptr != m_pzmq->context_zmq) delete m_pzmq->context_zmq;
    m_pzmq->context_zmq = nullptr;

    try {
        m_pzmq->context_zmq = new zmq::context_t(
            1, 31); // Threads, Max Sockets. (31 is a sane default).
    }
    catch (std::exception& e) {
        OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__, e.what());
        OT_FAIL;
    }

    m_HasContext = true;
    return true;
}

bool OTSocket_ZMQ_4::RemakeSocket(const bool bNewContext /*= false*/)
{

    if (!m_bInitialized) return false;
    if (!m_HasContext) return false;

    if (!m_bConnected || !m_bListening) return false;
    if (m_bConnected && m_bListening) return false;

    bool bConnected = m_bConnected;
    bool bListening = m_bListening;

    if (bNewContext) NewContext();

    if (bConnected) return Connect();
    if (bListening) return Listen();

    return false;
}

bool OTSocket_ZMQ_4::Connect()
{
    if (!m_bInitialized) {
        OT_FAIL;
    }
    if (!m_HasContext) {
        OT_FAIL;
    }

    if (nullptr == m_pzmq->context_zmq) {
        OTLog::vError("%s: Error: %s must exist to Listen!\n", __FUNCTION__,
                      "m_pzmq->context_zmq");
        OT_FAIL;
    }
    if (true == m_bListening) {
        OTLog::vError("%s: Error: Must not be Listening, to Connect!\n",
                      __FUNCTION__);
        OT_FAIL;
    }

    if (!NewSocket(true)) return false; // NewSocket(true), Request Socket.

    try {
        m_pzmq->socket_zmq->connect(connectPath_.c_str());
    }
    catch (std::exception& e) {
        OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__, e.what());
        OT_FAIL;
    }

    m_bConnected = true;
    return true;
}

bool OTSocket_ZMQ_4::Listen()
{
    if (!m_bInitialized) {
        OT_FAIL;
    }
    if (!m_HasContext) {
        OT_FAIL;
    }

    if (nullptr == m_pzmq->context_zmq) {
        OTLog::vError("%s: Error: %s must exist to Listen!\n", __FUNCTION__,
                      "m_pzmq->context_zmq");
        OT_FAIL;
    }
    if (true == m_bConnected) {
        OTLog::vError("%s: Error: Must not be Connected, to Listen!\n",
                      __FUNCTION__);
        OT_FAIL;
    }

    if (!NewSocket(false)) return false; // NewSocket(false), Responce Socket.

    try {
        m_pzmq->socket_zmq->bind(bindingPath_.c_str());
    }
    catch (std::exception& e) {
        OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__, e.what());
        OT_FAIL;
    }

    m_bListening = true;
    return true;
}

bool OTSocket_ZMQ_4::Connect(const std::string& connectPath)
{
    if (5 > connectPath.size()) {
        OTLog::vError("%s: Error: %s is too short!\n", __FUNCTION__,
                      "connectPath");
        OT_FAIL;
    }

    connectPath_ = connectPath;

    return (Connect());
}

bool OTSocket_ZMQ_4::Listen(const std::string& bindingPath)
{
    if (5 > bindingPath.size()) {
        OTLog::vError("%s: Error: %s is too short!\n", __FUNCTION__,
                      "bindingPath");
        OT_FAIL;
    }

    bindingPath_ = bindingPath;

    return (Listen());
}

bool OTSocket_ZMQ_4::Send(const OTASCIIArmor& ascEnvelope)
{
    if (!m_bInitialized) {
        OT_FAIL;
    }

    if (0 >= ascEnvelope.GetLength()) {
        OTLog::vError("%s: Error: %s is zero length!\n", __FUNCTION__,
                      "ascEnvelope");
        OT_FAIL;
    }
    m_ascLastMsgSent.Set(ascEnvelope); // In case we need to re-send.

    if (!m_HasContext) {
        OT_FAIL;
    }
    if (nullptr == m_pzmq->context_zmq) {
        OTLog::vError("%s: Error: %s must exist to Send!\n", __FUNCTION__,
                      "m_pzmq->context_zmq");
        OT_FAIL;
    }

    if (!m_bConnected && !m_bListening) return false;
    if (m_bConnected && m_bListening) return false;
    if (nullptr == m_pzmq->socket_zmq) {
        OTLog::vError("%s: Error: %s must exist to Send!\n", __FUNCTION__,
                      "m_pzmq->socket_zmq");
        OT_FAIL;
    }

    // -----------------------------------
    const int64_t lLatencySendMilliSec = m_lLatencySendMs;

    zmq::message_t zmq_message(ascEnvelope.GetLength());
    memcpy(zmq_message.data(), ascEnvelope.Get(), ascEnvelope.GetLength());

    bool bSuccessSending = false;

    if (m_bIsBlocking) {
        try {
            // Blocking.
            bSuccessSending = m_pzmq->socket_zmq->send(zmq_message);
        }
        catch (std::exception& e) {
            OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                          e.what());
            OT_FAIL;
        }
    }
    else // not blocking
    {
        int32_t sendTries = m_nLatencySendNoTries;
        int64_t doubling = lLatencySendMilliSec;

        while (sendTries > 0) {
            zmq::pollitem_t items[] = {
                {(*m_pzmq->socket_zmq), 0, ZMQ_POLLOUT, 0}};

            int nPoll = 0;
            try {
                // ZMQ_POLLOUT, 1 item, timeout (milliseconds)
                nPoll = zmq::poll(&items[0], 1, doubling);
            }
            catch (std::exception& e) {
                OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                              e.what());
                OT_FAIL;
            }

            doubling *= 2;

            if (items[0].revents & ZMQ_POLLOUT) {
                try {
                    bSuccessSending = m_pzmq->socket_zmq->send(
                        zmq_message,
                        ZMQ_NOBLOCK); // <=========== SEND ===============
                }
                catch (std::exception& e) {
                    OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                                  e.what());
                    OT_FAIL;
                }

                if (bSuccessSending || !HandleSendingError()) {
                    // Success, or the error is such that we do not want to
                    // retry.
                    break;
                }
            }
            else if (nPoll == -1) // error.
            {
                if (!HandlePollingError()) break;
            }

            --sendTries;
        }
    }

    return bSuccessSending;
}

bool OTSocket_ZMQ_4::Send(const OTASCIIArmor& ascEnvelope,
                          const std::string& connectPath)
{
    if (connectPath_ != connectPath) Connect(connectPath);

    if (!m_bConnected) OT_FAIL;

    return Send(ascEnvelope);
}

bool OTSocket_ZMQ_4::Receive(std::string& serverReply)
{
    if (!m_bInitialized) {
        OT_FAIL;
    }
    if (!m_HasContext) {
        OT_FAIL;
    }
    if (nullptr == m_pzmq->context_zmq) {
        OTLog::vError("%s: Error: %s must exist to Receive!\n", __FUNCTION__,
                      "m_pzmq->context_zmq");
        OT_FAIL;
    }

    if (!m_bConnected && !m_bListening) return false;
    if (m_bConnected && m_bListening) return false;
    if (nullptr == m_pzmq->socket_zmq) {
        OTLog::vError("%s: Error: %s must exist to Receive!\n", __FUNCTION__,
                      "m_pzmq->socket_zmq");
        OT_FAIL;
    }

    // -----------------------------------
    const int64_t lLatencyRecvMilliSec = m_lLatencyReceiveMs;

    //  Get the reply.
    zmq::message_t zmq_message;

    bool bSuccessReceiving = false;

    // If failure receiving, re-tries 2 times, with 4000 ms max delay between
    // each (Doubling every time.)
    if (m_bIsBlocking) {
        try {
            // Blocking.
            bSuccessReceiving = m_pzmq->socket_zmq->recv(&zmq_message);
        }
        catch (std::exception& e) {
            OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                          e.what());
            OT_FAIL;
        }
    }
    else // not blocking
    {
        int64_t doubling = lLatencyRecvMilliSec;
        int32_t receiveTries = m_nLatencyReceiveNoTries;
        while (receiveTries > 0) {
            //  Poll socket for a reply, with timeout
            zmq::pollitem_t items[] = {{*m_pzmq->socket_zmq, 0, ZMQ_POLLIN, 0}};

            int nPoll = 0;
            try {
                // ZMQ_POLLIN, 1 item, timeout (milliseconds)
                nPoll = zmq::poll(&items[0], 1, doubling);
            }
            catch (std::exception& e) {
                OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                              e.what());
                OT_FAIL;
            }

            doubling *= 2;

            //  If we got a reply, process it
            if (items[0].revents & ZMQ_POLLIN) {
                try {
                    bSuccessReceiving = m_pzmq->socket_zmq->recv(
                        &zmq_message,
                        ZMQ_NOBLOCK); // <=========== RECEIVE ===============
                }
                catch (std::exception& e) {
                    OTLog::vError("%s: Exception Caught: %s \n", __FUNCTION__,
                                  e.what());
                    OT_FAIL;
                }

                if (bSuccessReceiving || !HandleReceivingError()) {
                    // Success, or the error is such that we do not want to
                    // retry.
                    break;
                }
            }
            else if (nPoll == -1) // error.
            {
                if (!HandlePollingError()) break;
            }

            --receiveTries;
        }
    }

    if (bSuccessReceiving && (zmq_message.size() > 0)) {
        serverReply = std::string(static_cast<const char*>(zmq_message.data()),
                                  zmq_message.size());
        // serverReply.MemSet(static_cast<const char*>(zmq_message.data()),
        //                       static_cast<uint32_t>(zmq_message.size()));
    }

    return (bSuccessReceiving && (zmq_message.size() > 0));
}

bool OTSocket_ZMQ_4::HandlePollingError()
{
    bool bRetVal = false;

    switch (errno) {
    // At least one of the members of the items array refers to a socket whose
    // associated ØMQ context was terminated.
    case ETERM:
        OTLog::Error("OTSocket::HandlePollingError: Failure: At least one of "
                     "the members of the items array refers to a socket whose "
                     "associated ØMQ context was terminated. (Deleting and "
                     "re-creating the context.)\n");
        NewContext();
        break;
    // The provided items was not valid (nullptr).
    case EFAULT:
        OTLog::Error("OTSocket::HandlePollingError: Failed: The provided "
                     "polling items were not valid (nullptr).\n");
        break;
    // The operation was interrupted by delivery of a signal before any events
    // were available.
    case EINTR:
        OTLog::Error("OTSocket::HandlePollingError: The operation was "
                     "interrupted by delivery of a signal before any events "
                     "were available. Re-trying...\n");
        bRetVal = true;
        break;
    default:
        OTLog::Error(
            "OTSocket::HandlePollingError: Default case. Re-trying...\n");
        bRetVal = true;
        break;
    }
    return bRetVal;
}

bool OTSocket_ZMQ_4::HandleSendingError()
{
    bool keepTrying = false;

    switch (errno) {
    // Non-blocking mode was requested and the message cannot be sent at the
    // moment.
    case EAGAIN:
        OTLog::vOutput(0, "OTSocket::HandleSendingError: Non-blocking mode was "
                          "requested and the message cannot be sent at the "
                          "moment. Re-trying...\n");
        keepTrying = true;
        break;
    // The zmq_send() operation is not supported by this socket type.
    case ENOTSUP:
        OTLog::Error("OTSocket::HandleSendingError: failure: The zmq_send() "
                     "operation is not supported by this socket type.\n");
        break;
    // The zmq_send() operation cannot be performed on this socket at the moment
    // due to the socket not being in the appropriate state. This error may
    // occur with socket types that switch between several states, such as
    // ZMQ_REP. See the messaging patterns section of zmq_socket(3) for more
    // information.
    case EFSM:
        OTLog::vOutput(0, "OTSocket::HandleSendingError: The zmq_send() "
                          "operation cannot be performed on this socket at the "
                          "moment due to the socket not being in the "
                          "appropriate state. Deleting socket and "
                          "re-trying...\n");
        RemakeSocket();
        keepTrying = true;
        break;
    // The ØMQ context associated with the specified socket was terminated.
    case ETERM:
        OTLog::Error("OTSocket::HandleSendingError: The ØMQ context associated "
                     "with the specified socket was terminated. (Deleting and "
                     "re-creating the context and the socket, and trying "
                     "again.)\n");
        RemakeSocket(true);
        keepTrying = true;
        break;
    // The provided socket was invalid.
    case ENOTSOCK:
        OTLog::Error("OTSocket::HandleSendingError: The provided socket was "
                     "invalid. (Deleting socket and re-trying...)\n");
        RemakeSocket();
        keepTrying = true;
        break;
    // The operation was interrupted by delivery of a signal before the message
    // was sent. Re-trying...
    case EINTR:
        OTLog::Error("OTSocket::HandleSendingError: The operation was "
                     "interrupted by delivery of a signal before the message "
                     "was sent. (Re-trying...)\n");
        keepTrying = true;
        break;
    // Invalid message.
    case EFAULT:
        OTLog::Error("OTSocket::HandleSendingError: Failure: The provided "
                     "pollitems were not valid (nullptr).\n");
        break;
    default:
        OTLog::Error(
            "OTSocket::HandleSendingError: Default case. Re-trying...\n");
        keepTrying = true;
        break;
    }
    return keepTrying;
}

bool OTSocket_ZMQ_4::HandleReceivingError()
{

    bool keepTrying = false;

    switch (errno) {
    // Non-blocking mode was requested and no messages are available at the
    // moment.
    case EAGAIN:
        OTLog::vOutput(0, "OTSocket::HandleReceivingError: Non-blocking mode "
                          "was requested and no messages are available at the "
                          "moment. Re-trying...\n");
        keepTrying = true;
        break;
    // The zmq_recv() operation is not supported by this socket type.
    case ENOTSUP:
        OTLog::Error("OTSocket::HandleReceivingError: Failure: The zmq_recv() "
                     "operation is not supported by this socket type.\n");
        break;
    // The zmq_recv() operation cannot be performed on this socket at the moment
    // due to the socket not being in the appropriate state. This error may
    // occur with socket types that switch between several states, such as
    // ZMQ_REP. See the messaging patterns section of zmq_socket(3) for more
    // information.
    case EFSM:
        OTLog::vOutput(0, "OTSocket::HandleReceivingError: The zmq_recv() "
                          "operation cannot be performed on this socket at the "
                          "moment due to the socket not being in the "
                          "appropriate state. (Deleting socket and "
                          "re-trying...)\n");
        RemakeSocket();
        {
            OTASCIIArmor ascTemp(m_ascLastMsgSent);
            keepTrying = Send(ascTemp);
        }
        break;
    // The ØMQ context associated with the specified socket was terminated.
    case ETERM:
        OTLog::Error("OTSocket::HandleReceivingError: The ØMQ context "
                     "associated with the specified socket was terminated. "
                     "(Re-creating the context, and trying again...)\n");
        RemakeSocket(true);
        {
            OTASCIIArmor ascTemp(m_ascLastMsgSent);
            keepTrying = Send(ascTemp);
        }
        break;
    // The provided socket was invalid.
    case ENOTSOCK:
        OTLog::Error("OTSocket::HandleReceivingError: The provided socket was "
                     "invalid. (Deleting socket and re-trying.)\n");
        RemakeSocket();
        {
            OTASCIIArmor ascTemp(m_ascLastMsgSent);
            keepTrying = Send(ascTemp);
        }
        break;
    // The operation was interrupted by delivery of a signal before a message
    // was available.
    case EINTR:
        OTLog::Error("OTSocket::HandleSendingError: The operation was "
                     "interrupted by delivery of a signal before the message "
                     "was sent. (Re-trying...)\n");
        keepTrying = true;
        break;
    // The message passed to the function was invalid.
    case EFAULT:
        OTLog::Error("OTSocket::HandleReceivingError: Failure: The message "
                     "passed to the function was invalid.\n");
        break;
    default:
        OTLog::Error(
            "OTSocket::HandleReceivingError: Default case. Re-trying...\n");
        keepTrying = true;
        break;
    }
    return keepTrying;
}

} // namespace opentxs
