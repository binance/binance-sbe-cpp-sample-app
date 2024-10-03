# C++ SBE Sample Application

This sample application is designed to decode responses from multiple endpoints, when using [Binance Spot API Simple Binary Encoding (SBE)](https://github.com/binance/binance-spot-api-docs/blob/master/faqs/sbe_faq.md):

- [`REST GET /api/v3/exchangeInfo`](#pipe-rest-exchangeinfo-sbe-response-into-sbe-sample-app)
- [`REST GET /api/v3/account`](#pipe-rest-account-sbe-response-into-sbe-sample-app)
- [`REST POST /api/v3/order`](#pipe-rest-new-order-sbe-response-into-sbe-sample-app)
- [`REST GET /api/v3/order`](#pipe-rest-query-order-info-sbe-response-into-sbe-sample-app)
- [`WebSocket exchangeInfo method`](#pipe-websocket-exchangeinfo-sbe-response-into-sbe-sample-app)

It decodes a payload from STDIN and prints it as JSON to STDOUT.
This sample application is currently supported on Linux and macOS.

## Getting Started

1. Clone the source code:

```shell
git clone git@github.com:binance/binance-sbe-cpp-sample-app.git
```

2. Navigate to the directory where the `main.cpp` file is located and use the following command to generate `sbe-sample-app`:

```shell
c++ -std=c++20 -Wextra -Wall -o sbe-sample-app ./main.cpp
```

## Usage

### Pipe REST ExchangeInfo SBE response into sbe-sample-app

The following command fetches the `exchangeInfo` SBE response from the REST API and has `sbe-sample-app` decode it and output it as JSON to STDOUT:

```shell
curl -X GET -H 'Accept: application/sbe' -H 'X-MBX-SBE: 1:0' \
    'https://api.binance.com/api/v3/exchangeInfo' \
    | ./sbe-sample-app
```

### Pipe REST Account SBE response into sbe-sample-app

The following commands fetch the `account` SBE response from the REST API and have `sbe-sample-app` decode it and output it as JSON to STDOUT:

#### HMAC keys

```shell
hmac_api_key="<your_api_key>"; \
    hmac_secret_key="<your_secret_key>"; \
    url_sans_query="https://api.binance.com/api/v3/account"; \
    query="timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -hmac "${hmac_secret_key}"); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${hmac_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### RSA keys

```shell
rsa_api_key="<your_api_key>"; \
    rsa_secret_path="<pem_file_path>"; \
    url_sans_query="https://api.binance.com/api/v3/account"; \
    query="timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -sign "${rsa_secret_path}" | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${rsa_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### ED25519 keys

```shell
ed25519_api_key="<your_api_key>"; \
    ed25519_secret_path="<pem_file_path>"; \
    url_sans_query="https://api.binance.com/api/v3/account"; \
    query="timestamp=$(date +%s000)"; \
    echo -n "${query}" > to_be_signed.txt; \
    signature=$(openssl pkeyutl -sign -inkey "${ed25519_secret_path}" -rawin -in to_be_signed.txt | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${ed25519_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

### Pipe REST New Order SBE response into sbe-sample-app

The following commands fetch the new `order` SBE response from the REST API when the `newOrderRespType` parameter is set to `RESULT` and have `sbe-sample-app` decode it and output it as JSON to STDOUT:

#### HMAC keys

```shell
hmac_api_key="<your_api_key>"; \
    hmac_secret_key="<your_secret_key>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&side=BUY&type=LIMIT&timeInForce=GTC&quantity=1&price=250&newOrderRespType=RESULT&timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -hmac "${hmac_secret_key}"); \
    signature=${signature#*= }; \
    curl -X POST -H "X-MBX-APIKEY: ${hmac_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### RSA keys

```shell
rsa_api_key="<your_api_key>"; \
    rsa_secret_path="<pem_file_path>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&side=BUY&type=LIMIT&timeInForce=GTC&quantity=1&price=250&newOrderRespType=RESULT&timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -sign "${rsa_secret_path}" | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X POST -H "X-MBX-APIKEY: ${rsa_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### ED25519 keys

```shell
ed25519_api_key="<your_api_key>"; \
    ed25519_secret_path="<pem_file_path>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&side=BUY&type=LIMIT&timeInForce=GTC&quantity=1&price=250&newOrderRespType=RESULT&timestamp=$(date +%s000)"; \
    echo -n "${query}" > to_be_signed.txt; \
    signature=$(openssl pkeyutl -sign -inkey "${ed25519_secret_path}" -rawin -in to_be_signed.txt | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X POST -H "X-MBX-APIKEY: ${ed25519_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

### Pipe REST Query Order info SBE response into sbe-sample-app

The following commands fetch the `order` info SBE response from the REST API and have `sbe-sample-app` decode it and output it as JSON to STDOUT:

#### HMAC keys

```shell
hmac_api_key="<your_api_key>"; \
    hmac_secret_key="<your_secret_key>"; \
    order_id="<your order ID>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&orderId=${order_id}&timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -hmac "${hmac_secret_key}"); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${hmac_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### RSA keys

```shell
rsa_api_key="<your_api_key>"; \
    rsa_secret_path="<pem_file_path>"; \
    order_id="<your order ID>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&orderId=${order_id}&timestamp=$(date +%s000)"; \
    signature=$(echo -n "${query}" | openssl dgst -sha256 -sign "${rsa_secret_path}" | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${rsa_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

#### ED25519 keys

```shell
ed25519_api_key="<your_api_key>"; \
    ed25519_secret_path="<pem_file_path>"; \
    order_id="<your order ID>"; \
    url_sans_query="https://api.binance.com/api/v3/order"; \
    query="symbol=BNBUSDT&orderId=${order_id}&timestamp=$(date +%s000)"; \
    echo -n "${query}" > to_be_signed.txt; \
    signature=$(openssl pkeyutl -sign -inkey "${ed25519_secret_path}" -rawin -in to_be_signed.txt | openssl enc -base64 -A); \
    signature=${signature#*= }; \
    curl -X GET -H "X-MBX-APIKEY: ${ed25519_api_key}" -H "Accept: application/sbe" -H "X-MBX-SBE: 1:0" \
    "${url_sans_query}?${query}&signature=${signature}" \
    | ./sbe-sample-app
```

### Pipe WebSocket ExchangeInfo SBE response into sbe-sample-app

The following command fetches the `exchangeInfo` SBE response from the WebSocket API and has `sbe-sample-app` decode it and output it as JSON to STDOUT:

```shell
echo '{"id":"93fb61ef-89f8-4d6e-b022-4f035a3fadad","method":"exchangeInfo","params":{"symbol":"BTCUSDT"}}' \
    | ./tools/websocket_send.py  'wss://ws-api.binance.com:443/ws-api/v3?responseFormat=sbe&sbeSchemaId=1&sbeSchemaVersion=0' \
    | ./sbe-sample-app
```

### Notes

- The code in the `main.cpp` file, along with the accompanying header files, is designed specifically for decoding the responses from the `exchangeInfo`, `account`, and `order` endpoints.
- There are additional decoder classes in the `spot_sbe` folder that can be useful for decoding SBE responses from other endpoints in the Binance Spot API.

### Testnet

To use the Spot Testnet API, you only need to replace:
- `api.binance.com` with `testnet.binance.vision` for the REST API
- `ws-api.binance.com` with `testnet.binance.vision` for the WebSocket API

### Code formatting

The C++ code in this repository was formatted by running:

```shell
clang-format-15 -i --style '{BasedOnStyle: chromium, IndentWidth: 4, ColumnLimit: 100}' *.h *.cpp
```

## Updates

### C++ decoders

The `spot_sbe` directory contains code generated by [simple-binary-encoding](https://github.com/real-logic/simple-binary-encoding), which you will likely want to reuse verbatim. However, if you would like to update it, please navigate to the root of this project and follow these steps:

1) Download the schema file ([spot_prod_latest.xml](https://github.com/binance/binance-spot-api-docs/blob/master/sbe/schemas/spot_prod_latest.xml)):

```shell
curl -o spot_latest.xml https://raw.githubusercontent.com/binance/binance-spot-api-docs/master/sbe/schemas/$(curl -s https://raw.githubusercontent.com/binance/binance-spot-api-docs/master/sbe/schemas/spot_prod_latest.xml)
```

**Note:** If you are using the Spot Testnet API, replace `spot_prod_latest.xml` with `spot_testnet_latest.xml` in the above `curl ` command.

2) Clone & build [simple-binary-encoding](https://github.com/real-logic/simple-binary-encoding):

```shell
git clone https://github.com/real-logic/simple-binary-encoding.git --branch 1.30.0 \
    && cd simple-binary-encoding \
    && ./gradlew \
    && cd ..
```

3) Run the SBE tool code generator built in the previous step:

```shell
java \
    -Dsbe.output.dir=. \
    -Dsbe.target.language=Cpp \
    -jar simple-binary-encoding/sbe-all/build/libs/sbe-all-1.30.0.jar \
    spot_latest.xml
```
