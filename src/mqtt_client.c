/**
 * @file    mqtt_client.c
 * @brief   MQTT Client - AWS IoT Core Integration
 * @author  Anjaneya Reddy Pondugula
 */

#include "mqtt_client.h"
#include <stdint.h>
#include <string.h>

#define MQTT_BROKER_PORT     8883U
#define MQTT_KEEP_ALIVE_SEC  60U
#define MQTT_TOPIC_TELEMETRY "device/telemetry"
#define MQTT_TOPIC_DIAGNOSTICS "device/diagnostics"
#define MQTT_MAX_PAYLOAD     256U

typedef enum {
    MQTT_DISCONNECTED = 0,
    MQTT_CONNECTING,
    MQTT_CONNECTED
} MQTT_State_t;

static MQTT_State_t mqtt_state = MQTT_DISCONNECTED;
static uint16_t     packet_id  = 0U;

MQTT_Status_t mqtt_init(const char *broker_url, const char *client_id)
{
    if (broker_url == NULL || client_id == NULL) {
        return MQTT_ERROR;
    }
    mqtt_state = MQTT_CONNECTING;
    /* Configure TLS/SSL for AWS IoT Core */
    /* Establish TCP connection to broker  */
    mqtt_state = MQTT_CONNECTED;
    return MQTT_OK;
}

MQTT_Status_t mqtt_publish(const char *topic, uint8_t *payload, uint16_t len)
{
    if (mqtt_state != MQTT_CONNECTED) {
        return MQTT_ERROR_NOT_CONNECTED;
    }
    if (topic == NULL || payload == NULL || len > MQTT_MAX_PAYLOAD) {
        return MQTT_ERROR;
    }
    packet_id++;
    /* Serialize MQTT PUBLISH packet */
    /* Transmit over TLS connection  */
    return MQTT_OK;
}

MQTT_Status_t mqtt_publish_telemetry(float temperature,
                                      float humidity,
                                      uint32_t timestamp)
{
    uint8_t payload[MQTT_MAX_PAYLOAD] = {0};
    uint16_t len = 0U;

    /* Build JSON payload */
    len = (uint16_t)snprintf((char *)payload, MQTT_MAX_PAYLOAD,
        "{\"temp\":%.2f,\"humidity\":%.2f,\"ts\":%lu}",
        temperature, humidity, timestamp);

    return mqtt_publish(MQTT_TOPIC_TELEMETRY, payload, len);
}

void mqtt_disconnect(void)
{
    /* Send MQTT DISCONNECT packet */
    mqtt_state = MQTT_DISCONNECTED;
}
