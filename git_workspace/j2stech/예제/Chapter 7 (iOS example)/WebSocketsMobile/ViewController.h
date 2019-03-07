//
//  ViewController.h
//  WebSocketsMobile
//
//  Created by Vangos Pterneas on 5/5/13.
//  Copyright (c) 2013 LightBuzz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WebSocket.h"

@interface ViewController : UIViewController <WebSocketDelegate>
{
    // Create a new WebSocket object.
    WebSocket *socket;
    
    __weak IBOutlet UITextField *textMessage;
    __weak IBOutlet UIButton *buttonSend;
    __weak IBOutlet UILabel *labelChat;    
}

- (IBAction)sendTapped:(id)sender;

@end
