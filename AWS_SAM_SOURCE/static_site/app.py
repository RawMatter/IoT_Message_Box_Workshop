import json

# import requests

page = open("index.html", "r").read()

def lambda_handler(event, context):

    return {
        'headers': {
            "Access-Control-Allow-Origin": "*",
            "Access-Control-Allow-Headers": "Content-Type",
            "Access-Control-Allow-Methods": "OPTIONS,POST",
            "content-type": "text/html"
        },
        "statusCode": 200,
        "body": page
        }
