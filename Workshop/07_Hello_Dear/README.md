# Hello Dear

Lets provide people with a nice interface for interacting with our DIY message box. Something they can access easily and makes it simple to send a message

## Websites are a thing
Lets host a website on AWS, its a good secondary function for a cloud provider when they have resources they dont want to dedicate to IoT functions. 

We can use Lambda functions to maintain the serverless nature of our design and they can even publish messages directly to the broker!

Sample code is provided for lambda functions and the permessions required in the `AWS_SAM_SOURCE` folder, located in the root directory

You can see the resulting page here. *Design is kinda my thing*

https://sq2lqttx4f.execute-api.ap-southeast-2.amazonaws.com/Prod

# Yes I'm Trustworthy
I need to make some coin back from hosting this workshop, so the next step involves launching some cloud formation code via this s3 URL.

`https://iot-workshop-cf.s3.ap-southeast-2.amazonaws.com/template.yaml`

In the AWS Console, open `cloud formation`

Create a new stack

`create stack` > `with new resources`

select `Amazon S3 Url` and input the URL above
Click through and wait for the URL from the Outputs

## Resources it deploys
This will save us diving into an AWS Lambda workshop too. It creates a few resources
1. An API gateway to direct API calls to lambda functions
2. A basic `GET` for the html of our website
3. A `POST` function to forward messages to the broker

The end point of our API is made availbe as an output on our cloudformation stack



