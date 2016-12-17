/*
 * WPA Supplicant / shared MSCHAPV2 helper functions
 *
 *
 */

#ifndef MS_FUNCS_H
#define MS_FUNCS_H

int esp_generate_nt_response(const u8 *auth_challenge, const u8 *peer_challenge,
			 const u8 *username, size_t username_len,
			 const u8 *password, size_t password_len,
			 u8 *response);

int esp_generate_nt_response_pwhash(const u8 *auth_challenge,
				const u8 *peer_challenge,
				const u8 *username, size_t username_len,
				const u8 *password_hash,
				u8 *response);
int esp_generate_authenticator_response(const u8 *password, size_t password_len,
				    const u8 *peer_challenge,
				    const u8 *auth_challenge,
				    const u8 *username, size_t username_len,
				    const u8 *nt_response, u8 *response);
int esp_generate_authenticator_response_pwhash(
	const u8 *password_hash,
	const u8 *peer_challenge, const u8 *auth_challenge,
	const u8 *username, size_t username_len,
	const u8 *nt_response, u8 *response);
int esp_nt_challenge_response(const u8 *challenge, const u8 *password,
			  size_t password_len, u8 *response);

void esp_challenge_response(const u8 *challenge, const u8 *password_hash,
			u8 *response);
int esp_nt_password_hash(const u8 *password, size_t password_len,
		     u8 *password_hash);
int esp_hash_nt_password_hash(const u8 *password_hash, u8 *password_hash_hash);
int esp_get_master_key(const u8 *password_hash_hash, const u8 *nt_response,
		   u8 *master_key);
int esp_get_asymetric_start_key(const u8 *master_key, u8 *session_key,
			    size_t session_key_len, int is_send,
			    int is_server);
int esp_encrypt_pw_block_with_password_hash(
	const u8 *password, size_t password_len,
	const u8 *password_hash, u8 *pw_block);
int __must_check encry_pw_block_with_password_hash(
	const u8 *password, size_t password_len,
	const u8 *password_hash, u8 *pw_block);
int __must_check esp_new_password_encrypted_with_old_nt_password_hash(
	const u8 *new_password, size_t new_password_len,
	const u8 *old_password, size_t old_password_len,
	u8 *encrypted_pw_block);
void esp_nt_password_hash_encrypted_with_block(const u8 *password_hash,
					   const u8 *block, u8 *cypher);
int esp_old_nt_password_hash_encrypted_with_new_nt_password_hash(
	const u8 *new_password, size_t new_password_len,
	const u8 *old_password, size_t old_password_len,
	u8 *encrypted_password_hash);

#endif /* MS_FUNCS_H */
