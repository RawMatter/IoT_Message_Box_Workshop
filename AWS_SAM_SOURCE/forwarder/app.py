import json
import boto3
import logging

logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

# import requests

device_topic = "message"
client = boto3.client('iot-data', region_name='ap-southeast-2')
logger.info("cold start")

def lambda_handler(event, context):
    code = 400
    
    logger.debug(event)
    data = json.loads(event['body'])
    message = data['message']

    response = client.publish(
        topic= device_topic,
        qos=1,
        payload=json.dumps({"message":message})
    )


    return {
        "statusCode": code,
        "body": ""
        }
