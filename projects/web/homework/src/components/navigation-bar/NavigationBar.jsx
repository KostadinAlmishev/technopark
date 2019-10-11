import React, { Component } from 'react';
import { Layout, Input, Avatar } from 'antd';

export default class NavigationBar extends Component {

    render() {
        return (
            <Layout.Header
             >
            {
                /*
                <Menu
                    theme='light'
                    mode='horizontal'
                    defaultSelectedKeys={['2']}
                    style={{ lineHeight: '64px' }}
                >
                    <Menu.Item key='1'>nav 1</Menu.Item>
                </Menu>
                */
            }
                <Input.Search
                    placeholder='input search text'
                    style={{ width: '500px' }}
                />
                <Avatar icon="user"/>

            
            </Layout.Header>
        )
    }
}
