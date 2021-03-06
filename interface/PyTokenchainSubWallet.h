// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SPVSDKPY_PYTOKENCHAINSUBWALLET_H
#define SPVSDKPY_PYTOKENCHAINSUBWALLET_H

#include <ITokenchainSubWallet.h>
#include "PySubWallet.h"

class PyTokenchainSubWallet : PySubWallet {
public:
	explicit PyTokenchainSubWallet(const PySubWallet &subWallet);
	/**
	 * Get balances of all addresses in json format.
	 * @param assetID asset hex code from asset hash.
	 * @return balances of all addresses in json format.
	 */
	virtual std::string GetBalanceInfo(const std::string &assetID) const;

	/**
	 * Get sum of balances of all addresses.
	 * @param assetID asset hex code from asset hash.
	 * @return sum of balances in big int string. 1 Token = "1.0000"
	 */
	virtual std::string GetBalance(const std::string &assetID) const;

	/**
	 * Get balance of only the specified address.
	 * @param assetID asset hex code from asset hash.
	 * @param address is one of addresses created by current sub wallet.
	 * @return balance of specified address in big int string.
	 */
	virtual std::string GetBalanceWithAddress(const std::string &assetID, const std::string &address) const;

	/**
	 * Register asset.
	 * @param name Asset name such as ELA, IDChain.
	 * @param description
	 * @param address Address where to receive registered asset amount.
	 * @param registerAmount Integer part amount.
	 * @param precision Range: [0, 18].
	 * @param memo
	 * @param remark
	 * @return Transaction in json format.
	 */
	virtual std::string CreateRegisterAssetTransaction(
		const std::string &name,
		const std::string &description,
		const std::string &registerToAddress,
		uint64_t registerAmount,
		uint8_t precision,
		const std::string &memo,
		const std::string &remark);

	/**
	 * Create a normal transaction and return the content of transaction in json format.
	 * @param fromAddress specify which address we want to spend, or just input empty string to let wallet choose UTXOs automatically.
	 * @param toAddress specify which address we want to send.
	 * @param amount specify amount(big int string) we want to send.
	 * @param assetID specify asset ID
	 * @param memo input memo attribute for describing.
	 * @param remark is used to record message of local wallet.
	 * @return If success return the content of transaction in json format.
	 */
	virtual std::string CreateTransaction(
		const std::string &fromAddress,
		const std::string &toAddress,
		const std::string &amount,
		const std::string &assetID,
		const std::string &memo,
		const std::string &remark);

	/**
	 * Get all assets in json format. Note this is a sub set of supported assets.
	 * @return assets list in json format
	 */
	virtual std::string GetAllAssets() const;

private:
	ITokenchainSubWallet *_tokenchainSubWallet;

};


#endif //SPVSDKPY_PYTOKENCHAINSUBWALLET_H
